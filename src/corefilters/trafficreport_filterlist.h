#ifndef UTM_TRAFFICREPORT_FILTERLIST_H
#define UTM_TRAFFICREPORT_FILTERLIST_H

#pragma once
#include <ubaselist.h>

#include "trafficreport_filter.h"

namespace utm {

class trafficreport_filterlist : public ubaselist<trafficreport_filter>
{
public:
	trafficreport_filterlist();
	trafficreport_filterlist(const trafficreport_filterlist& rhs) { operator=(rhs); };
	~trafficreport_filterlist();

	void xml_create();
	void xml_catch_value(const char *keyname, const char *keyvalue) { };
	ubase* xml_catch_subnode(const char *tag_name, const char *class_name);
};

}

#endif // UTM_TRAFFICREPORT_FILTERLIST_H
