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

#ifndef HEADLESS

#include "MTLFuncs.h"


MTL_DECLARE_LIB_HANDLE();

jboolean
MTLFuncs_OpenLibrary()
{
    J2dRlsTraceLn(J2D_TRACE_INFO, "MTLFuncs_OpenLibrary");


    return JNI_TRUE;
}

void
MTLFuncs_CloseLibrary()
{
    J2dRlsTraceLn(J2D_TRACE_INFO, "MTLFuncs_CloseLibrary");

}

jboolean
MTLFuncs_InitPlatformFuncs()
{
    J2dRlsTraceLn(J2D_TRACE_INFO, "MTLFuncs_InitPlatformFuncs");

    return JNI_TRUE;
}

jboolean
MTLFuncs_InitBaseFuncs()
{
    J2dRlsTraceLn(J2D_TRACE_INFO, "MTLFuncs_InitBaseFuncs");


    return JNI_TRUE;
}

jboolean
MTLFuncs_InitExtFuncs()
{
    J2dRlsTraceLn(J2D_TRACE_INFO, "MTLFuncs_InitExtFuncs");

    return JNI_TRUE;
}

#endif /* !HEADLESS */
