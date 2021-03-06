/*
 * BlueZ-Lib - C API library for BlueZ
 *
 * Copyright (c) 2013-2016 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *              http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __BLUEZ_COMMON_H__
#define __BLUEZ_COMMON_H__

#include <stdint.h>
#include <glib.h>
#include <gio/gio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BLUEZ_SERVICE_NAME "org.bluez"
#define BLUEZ_MANAGER_PATH "/"
#define AGENT_PATH "/org/bluez/agent"
#define ADAPTER_INTERFACE "org.bluez.Adapter1"
#define DEVICE_INTERFACE "org.bluez.Device1"
#define SERVICE_INTERFACE "org.bluez.Service1"
#define AGENT_INTERFACE "org.bluez.AgentManager1"
#define PROFILE_INTERFACE "org.bluez.ProfileManager1"
#define PROPERTIES_INTERFACE "org.freedesktop.DBus.Properties"

typedef enum {
	BT_RESULT_OK,
	BT_RESULT_INVALID_ARGS,
	BT_RESULT_NOT_READY,
	BT_RESULT_IN_PROGRESS,
	BT_RESULT_ALREADY_EXISTS,
	BT_RESULT_NOT_SUPPORTED,
	BT_RESULT_NOT_CONNECTED,
	BT_RESULT_ALREADY_CONNECTED,
	BT_RESULT_NOT_AVAILABLE,
	BT_RESULT_NOT_EXIST,
	BT_RESULT_NO_ADAPTER,
	BT_RESULT_NO_AGENT,
	BT_RESULT_NOT_AUTHORIZED,
	BT_RESULT_FAILED
} BTResult;

const gchar *ret2str(BTResult ret);

typedef void (*bluez_response_cb) (BTResult ret,
				GVariant *data, void *user_data);

void proxy_method_call_with_reply(GDBusProxy *proxy, const gchar *name,
		GVariant *parameter, bluez_response_cb func, void *user_data);

BTResult proxy_method_call(GDBusProxy *proxy, const gchar *name,
							GVariant *parameter);

gboolean property_get_boolean(GDBusProxy *proxy, const gchar *name,
							gboolean *value);

gboolean property_get_int16(GDBusProxy *proxy, const gchar *name,
							gint16 *value);

gboolean property_get_uint32(GDBusProxy *proxy, const gchar *name,
							guint32 *value);

gchar *property_get_string(GDBusProxy *proxy, const gchar *name);

gchar **property_get_strings(GDBusProxy *proxy, const gchar *name);

BTResult property_set_variant(GDBusProxy *proxy, GVariant *variant);

gchar *get_addrstr_from_path(const gchar *path);

#ifdef __cplusplus
}
#endif

#endif
