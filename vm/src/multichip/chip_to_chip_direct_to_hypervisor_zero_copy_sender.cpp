/******************************************************************************
 *  Copyright (c) 2008 - 2010 IBM Corporation and others.
 *  All rights reserved. This program and the accompanying materials
 *  are made available under the terms of the Eclipse Public License v1.0
 *  which accompanies this distribution, and is available at
 *  http://www.eclipse.org/legal/epl-v10.html
 * 
 *  Contributors:
 *    David Ungar, IBM Research - Initial Implementation
 *    Sam Adams, IBM Research - Initial Implementation
 *    Stefan Marr, Vrije Universiteit Brussel - Port to x86 Multi-Core Systems
 ******************************************************************************/


# if Multiple_Tileras

#include "headers.h"

void Chip_to_Chip_Direct_to_Hypervisor_Zero_Copy_Sender::check_completion() {
  Chip_to_Chip_Direct_to_Hypervisor_Zero_Copy_Endpoint::check_completion();
  assert_always_eq(completion.size, command.size);
}




# endif // Multiple_Tileras