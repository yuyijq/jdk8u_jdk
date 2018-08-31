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

#ifndef MTLBufImgOps_h_Included
#define MTLBufImgOps_h_Included

#include "MTLContext.h"

void MTLBufImgOps_EnableConvolveOp(MTLContext *mtlc, jlong pSrcOps,
                                   jboolean edgeZeroFill,
                                   jint kernelWidth, jint KernelHeight,
                                   unsigned char *kernelVals);
void MTLBufImgOps_DisableConvolveOp(MTLContext *mtlc);
void MTLBufImgOps_EnableRescaleOp(MTLContext *mtlc, jlong pSrcOps,
                                  jboolean nonPremult,
                                  unsigned char *scaleFactors,
                                  unsigned char *offsets);
void MTLBufImgOps_DisableRescaleOp(MTLContext *mtlc);
void MTLBufImgOps_EnableLookupOp(MTLContext *mtlc, jlong pSrcOps,
                                 jboolean nonPremult, jboolean shortData,
                                 jint numBands, jint bandLength, jint offset,
                                 void *tableValues);
void MTLBufImgOps_DisableLookupOp(MTLContext *mtlc);

#endif /* MTLBufImgOps_h_Included */
