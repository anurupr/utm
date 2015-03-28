#include "StdAfx.h"
#include "monitor_result.h"

namespace utm {

const gchar* monitor_result::ping_status_str[] = { _U("?"), _U("OK"), _U("Offline"), _U("QualityDrop") };
const int monitor_result::ping_status_int[] = { PING_STATUS_UNKNOWN, PING_STATUS_OK, PING_STATUS_OFFLINE, PING_STATUS_QUALITYDROP };
	
monitor_result::monitor_result(void)
{
}

monitor_result::~monitor_result(void)
{
}

void monitor_result::analyze_and_set_new_status(monitor_result& mr, bool supress_quality_drop_status)
{
	unsigned int prev_status = mr.status;

	if (mr.curr_serial_reply_count == 0)
	{
		// �� ���� ����� �� ���� ������� �� ��� - ������ OFFLINE
		mr.status = PING_STATUS_OFFLINE;
	}
	else
	{
		// �� ������� ���� ���� ���� ��������

		if ((mr.curr_serial_request_count <= mr.curr_serial_reply_count) || (supress_quality_drop_status))
		{
			// ��� ����� ��������� ��������� ��� ��� �������� ��������� ���������� ��������� ����
			// 'supress qualitydrop status'
			mr.status = PING_STATUS_OK;
		}
		else
		{
			// �� ��� ����� ���������
			mr.status = PING_STATUS_QUALITYDROP;
		}
	}
}

}
