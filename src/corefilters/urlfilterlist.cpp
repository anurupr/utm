#include "StdAfx.h"
#include "urlfilterlist.h"

namespace utm {

const char urlfilterlist::this_class_name[] = "urlfilterlist";

urlfilterlist::urlfilterlist(void)
{
}


urlfilterlist::~urlfilterlist(void)
{
}

bool urlfilterlist::operator==(const urlfilterlist& rhs) const
{
	return items == rhs.items;
}

void urlfilterlist::clear()
{
	ubaselist::clear();
}
    
void urlfilterlist::xml_create()
{
    xml_append_root("UrlfilterList");
    xml_append_node(URLFILTERLIST_XMLTAG_URLFILTER, items);
}

void urlfilterlist::xml_catch_value(const char *keyname, const char *keyvalue)
{
	return;
}

ubase* urlfilterlist::xml_catch_subnode(const char *keyname)
{
	ubase *u = NULL;

	if (strcmp(keyname, URLFILTERLIST_XMLTAG_URLFILTER) == 0)
	{
		urlfilter* r = insert_and_get_inserted();
		u = dynamic_cast<ubase *>(r);
	}

	return u;
}

#ifdef UTM_DEBUG
void urlfilterlist::test_fillparams(int test_num)
{
	urlfilter u;
	u.name.assign("Unwanted sites");
	u.is_any_filter = true;
	u.fids.add_id(9);
	u.fids.add_id(18);
	u.urlrules.push_back("mail.ru");
	u.urlrules.push_back("rambler.ru");
	u.urlrules.push_back("utro.ru");

	add_element(u, 0);

	size_t count = items.size();

	return;
}
#endif

}