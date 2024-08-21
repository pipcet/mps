/* prmci3.c: MUTATOR CONTEXT (INTEL 386)
 *
 * $Id$
 * Copyright (c) 2001-2020 Ravenbrook Limited.  See end of file for license.
 *
 * .design: See <design/prmc> for the generic design of the interface
 * which is implemented in this module, including the contracts for the
 * functions.
 *
 * .purpose: Implement the mutator context module. <design/prmc>.
 *
 * .requirements: Current requirements are for limited support only, for
 * stepping the sorts of instructions that the Dylan compiler might
 * generate for table vector access - i.e., a restricted subset of MOV
 * addressing modes.  This avoids the need to scan entire weak tables at
 * an inappropriate rank when a page fault occurs.
 *
 *
 * SOURCES
 *
 * .source.i486: Intel486 Microprocessor Family Programmer's
 * Reference Manual
 *
 * .source.dylan: Dylan table code implementation. Especially the
 * following HOPE units:
 *  D-lib-dylan!table.dylan  (class <entry-vector>, slot entry-element)
 *  D-dfmc-harp-cg!harp-primitives.dylan (method op--repeated-slot-element)
 *  D-harp-pentium-harp!moves.dylan (pentium-template ld-index)
 *
 *
 * ASSUMPTIONS
 *
 * .assume.null: It's always safe for MutatorContextCanStepInstruction
 * to return FALSE. A null implementation of this module would be
 * overly conservative but otherwise correct.
 *
 * .assume.want: The Dylan implementation is likely to access a
 * weak table vector using either MOV r/m32,r32 or MOV r32,r/m32
 * instructions, where the r/m32 operand will be of one of the forms
 * disp8[reg], disp8[reg1][reg2], disp8[reg1][reg2*4] (see .source.dylan
 * and .source.i486)
 *
 * .assume.i3: Assume the following about the i386 environment:
 *   Steppable instructions (.assume.want) use the CS, DS & SS
 *   segment registers only (see .source.i486 Table 2-3).
 *   The processor runs in 32 bit mode.
 *   The CS, DS and SS segment registers all describe identical 32-
 *   bit flat address spaces.
 */

#include "mpm.h"
#include "prmci3.h"

SRCID(prmci3, "$Id$");

#if !defined(MPS_ARCH_I3)
#error "prmci3.c is specific to MPS_ARCH_I3"
#endif


Bool MutatorContextCanStepInstruction(MutatorContext context)
{
  AVERT(MutatorContext, context);

  return FALSE;
}


Res MutatorContextStepInstruction(MutatorContext context)
{
  Size inslen;
  MRef src;
  MRef dest;

  AVERT(MutatorContext, context);

  return ResUNIMPL;
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
