/* GStreamer
 *
 * Copyright (C) 2019 Collabora Ltd.
 *   Author: Stéphane Cerveau <scerveau@collabora.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library (COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#ifndef __GSTMPDSNODE_H__
#define __GSTMPDSNODE_H__

#include <gst/gst.h>
#include "gstmpdhelper.h"

G_BEGIN_DECLS

#define GST_TYPE_MPD_S_NODE gst_mpd_s_node_get_type ()
#define GST_MPD_S_NODE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GST_TYPE_MPD_S_NODE, GstMPDSNode))
#define GST_MPD_S_NODE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), GST_TYPE_MPD_S_NODE, GstMPDSNodeClass))
#define GST_IS_MPD_S_NODE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GST_TYPE_MPD_S_NODE))
#define GST_IS_MPD_S_NODE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), GST_TYPE_MPD_S_NODE))
#define GST_MPD_S_NODE_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), GST_TYPE_MPD_S_NODE, GstMPDSNodeClass))

typedef struct _GstMPDSNode                GstMPDSNode;
typedef struct _GstMPDSNodeClass           GstMPDSNodeClass;


struct _GstMPDSNode
{
  GstObject parent_instance;
  guint64 t;
  guint64 d;
  gint r;
};

struct _GstMPDSNodeClass {
  GstObjectClass parent_class;
};


G_GNUC_INTERNAL GType gst_mpd_s_node_get_type (void);

GstMPDSNode * gst_mpd_s_node_new (void);
void gst_mpd_s_node_free (GstMPDSNode* self);

GstMPDSNode *gst_mpd_s_node_clone (GstMPDSNode * pointer);

G_END_DECLS

#endif /* __GSTMPDSNODE_H__ */