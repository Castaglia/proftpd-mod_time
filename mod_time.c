/*
 * ProFTPD - mod_time
 * Copyright (c) 2002-2017 TJ Saunders
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA.
 *
 * As a special exemption, TJ Saunders and other respective copyright holders
 * give permission to link this program with OpenSSL, and distribute the
 * resulting executable, without including the source code for OpenSSL in the
 * source distribution.
 *
 * -----DO NOT EDIT BELOW THIS LINE-----
 * $Archive: mod_time.a $
 */

#include "mod_time.h"

extern xaset_t *server_list;

module time_module;

int time_logfd = -1;
pool *time_pool = NULL;

static const char *trace_channel = "time";

/* Module API tables
 */

static conftable time_conftab[] = {
  { "<Time>",			start_time,			NULL },
  { "</Time>",			finish_time,			NULL },

  { NULL }
};

module time_module = {
  /* Always NULL */
  NULL, NULL,

  /* Module API version */
  0x20,

  /* Module name */
  "time",

  /* Module configuration handler table */
  time_conftab,

  /* Module command handler table */
  time_cmdtab,

  /* Module authentication handler table */
  NULL,

  /* Module initialization */
  time_init,

  /* Session initialization */
  time_sess_init,

  /* Module version */
  MOD_TIME_VERSION
};

