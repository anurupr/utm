#ifndef _UTM_PROCNICKNAME_H
#define _UTM_PROCNICKNAME_H

#pragma once

#include "procnickname_base.h"

#define MAX_PROCNICKNAME_SIZE 18

namespace utm {

class procnickname : public procnickname_base
{
public:
	static const char this_class_name[];

public:
	procnickname(void);
	procnickname(const gstring& _nickname, const gstring& _pathexe);
	~procnickname(void);

	const char *get_this_class_name() const { return this_class_name; };

	void set_id(unsigned int id) { nid = id; };
	unsigned int get_id() const { return nid; };
	const gstring& get_name() const { return nickname; };
};

}

#endif // _UTM_PROCNICKNAME_H