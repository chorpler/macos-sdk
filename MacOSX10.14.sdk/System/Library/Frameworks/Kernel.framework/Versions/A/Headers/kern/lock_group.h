/*
 * Copyright (c) 2018 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
#ifndef _KERN_LOCK_GROUP_H
#define _KERN_LOCK_GROUP_H

#include <kern/queue.h>
#include <mach/mach_types.h>

#define LCK_GRP_NULL    (lck_grp_t *)0


typedef unsigned int    lck_type_t;

#define LCK_TYPE_SPIN   1
#define LCK_TYPE_MTX    2
#define LCK_TYPE_RW     3

typedef struct _lck_grp_ lck_grp_t;

typedef struct __lck_grp_attr__ lck_grp_attr_t;

#define LCK_GRP_ATTR_NULL       (lck_grp_attr_t *)0

__BEGIN_DECLS

extern  lck_grp_attr_t  *lck_grp_attr_alloc_init(
	void);

extern  void                    lck_grp_attr_setdefault(
	lck_grp_attr_t  *attr);

extern  void                    lck_grp_attr_setstat(
	lck_grp_attr_t  *attr);

extern  void                    lck_grp_attr_free(
	lck_grp_attr_t  *attr);

extern  lck_grp_t               *lck_grp_alloc_init(
	const char*             grp_name,
	lck_grp_attr_t  *attr);

extern void                             lck_grp_free(
	lck_grp_t               *grp);

__END_DECLS


#endif /* _KERN_LOCK_GROUP_H */
