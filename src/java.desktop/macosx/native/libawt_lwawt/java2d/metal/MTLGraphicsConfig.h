/*
 * Copyright 2018 JetBrains s.r.o.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#ifndef MTLGraphicsConfig_h_Included
#define MTLGraphicsConfig_h_Included

#import "jni.h"
#import "MTLSurfaceDataBase.h"
#import "MTLContext.h"
#import <Cocoa/Cocoa.h>
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>


@interface MTLGraphicsConfigUtil : NSObject {}
+ (void) _getMTLConfigInfo: (NSMutableArray *)argValue;
@end

// REMIND: Using an NSOpenGLPixelBuffer as the scratch surface has been
// problematic thus far (seeing garbage and flickering when switching
// between an NSView and the scratch surface), so the following enables
// an alternate codepath that uses a hidden NSWindow/NSView as the scratch
// surface, for the purposes of making a context current in certain
// situations.  It appears that calling [NSOpenGLContext setView] too
// frequently contributes to the bad behavior, so we should try to avoid
// switching to the scratch surface whenever possible.

/* Do we need this if we are using all off-screen drawing ? */
#define USE_NSVIEW_FOR_SCRATCH 1

/* Uncomment to have an additional CAOGLLayer instance tied to
 * each instance, which can be used to test remoting the layer
 * to an out of process window. The additional layer is needed
 * because a layer can only be attached to one context (view/window).
 * This is only for testing purposes and can be removed if/when no
 * longer needed.
 */


/**
 * The MTLGraphicsConfigInfo structure contains information specific to a
 * given CGLGraphicsConfig (pixel format).
 *
 *     jint screen;
 * The screen and PixelFormat for the associated CGLGraphicsConfig.
 *
 *     NSOpenGLPixelFormat *pixfmt;
 * The pixel format of the native NSOpenGL context.
 *
 *     OGLContext *context;
 * The context associated with this CGLGraphicsConfig.
 */
typedef struct _MTLGraphicsConfigInfo {
    jint                screen;
    NSOpenGLPixelFormat *pixfmt;
    MTLContext          *context;
} MTLGraphicsConfigInfo;

/**
 */
typedef struct _MTLCtxInfo {
    id<MTLDevice>               mtlDevice;
    id<MTLLibrary>              mtlLibrary;
    id<MTLRenderPipelineState>  mtlPipelineState;
    id<MTLBuffer>               mtlUniformBuffer;
    id<MTLCommandQueue>         mtlCommandQueue;
    id<MTLCommandBuffer>        mtlCommandBuffer;
    struct FrameUniforms*       mtlUniforms;
    id<CAMetalDrawable>         mtlDrawable;
    BOOL                        mtlEmptyCommandBuffer;
    id<MTLBuffer>               mtlVertexBuffer;
    NSView*                     scratchSurface;
    NSString*                   mtlShadersLib;
    jint                        mtlColor;
} MTLCtxInfo;

#endif /* MTLGraphicsConfig_h_Included */
