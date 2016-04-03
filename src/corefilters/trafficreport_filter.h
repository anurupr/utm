#pragma once
#include "trafficreport_filter_base.h"

namespace utm {

class trafficreport_filter : public trafficreport_filter_base
{
public:
	static const char this_class_name[];

public:
	trafficreport_filter();
	~trafficreport_filter();

	const char *get_this_class_name() const { return this_class_name; };

	ubase* xml_catch_subnode(const char *tag_name, const char *class_name);
	void xml_catch_subnode_finished(const char *keyname);

	void xml_catch_subnode_attribute(const char *attrname, const char* attrvalue);
	void xml_catch_rootnode_attribute(const char *attrname, const char* attrvalue);

	void set_id(unsigned int id);
	unsigned int get_id() const;

	bool xml_has_root_attr() const;
	void xml_get_root_attr(xmlattr_container& attr);

	void update_counters(const utime& ctm, __int64 sent, __int64 recv, const gstring& name);

private:
	unsigned int id;

public:
#ifdef UTM_DEBUG
	static void test_all();
#endif
};

}