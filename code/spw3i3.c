/* spw3i3.c: STACK PROBE FOR 32-BIT WINDOWS
 *
 * $Id$
 * Copyright (c) 2001-2020 Ravenbrook Limited.  See end of file for license.
 * Portions copyright (C) 2001 Global Graphics Software.
 *
 * This function reads a location that is depth words beyond the
 * current stack pointer. On Intel platforms, the stack grows
 * downwards, so this means reading from a location with a lesser
 * address.
 */


#include "mpm.h"

#if !defined(MPS_OS_W3) || !defined(MPS_ARCH_I3)
#error "spw3i3.c is specific to MPS_OS_W3 and MPS_ARCH_I3"
#endif

#ifdef MPS_BUILD_PC

/* "[ISO] Inline assembly code is not portable." */
#pragma warn(disable: 2007)

#endif /* MPS_BUILD_PC */


void StackProbe(Size depth)
{
#ifdef __GNUC__
  asm volatile("mov (%%esp, %%eax, 4), %%eax" : "=a" (depth) : "0" (-depth) : "memory");
#else
  __asm {
    mov  eax, depth
    neg  eax
    mov  eax, [esp+eax*4] /* do the actual probe */
  }
#endif
}


/* C. COPYRIGHT AND LICENSE
 *
 * Copyright (C) 2001-2020 Ravenbrook Limited <https://www.ravenbrook.com/>.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
