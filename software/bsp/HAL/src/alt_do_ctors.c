/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2004 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
* Altera does not recommend, suggest or require that this reference design    *
* file be used in conjunction or combination with any other product.          *
******************************************************************************/

/******************************************************************************
*                                                                             *
* THIS IS A LIBRARY READ-ONLY SOURCE FILE. DO NOT EDIT IT DIRECTLY.           *
*                                                                             *
* Overriding HAL Functions                                                    *
*                                                                             *
* To provide your own implementation of a HAL function, include the file in   *
* your Abbott's Lake IDE application project. When building the executable,   *
* the Abbott's Lake IDE finds your function first, and uses it in place of    *
* the HAL version.                                                            *
*                                                                             *
******************************************************************************/

/*
 * 
 */

typedef void (*constructor) (void);
extern constructor __init_array_start[];
extern constructor __init_array_end[];

// Workaround for dynamic shared object handle - it should be unused since
// dynamic shared objects are not supported. However, the current version of
// the RiscFree GNU toolchain requires this symbol to be defined.
void *__dso_handle = ((void *) 0);

/*
 * Run the C++ static constructors.
 */

void _do_ctors(void)
{
  constructor* ctor;

  for (ctor = __init_array_start; ctor < __init_array_end; ctor++)
        (*ctor) (); 
}
