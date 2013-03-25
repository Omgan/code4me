/**
 *@author gonggai
 */

#include <string>
#include <vector>
#include "strutil.h"

extern "C" int is_utf8_string(
		char *utf);

extern "C" void utf8_to_pinyin(
        char *in, 
        char *out,
        int first_letter_only, 
        int polyphone_support,
        int add_blank,
        int convert_double_char,
        char *overage_buff
        );

extern "C" int output_baijiaxing() {
	std::vector<std::string> names;
	names.push_back("��Ǯ���� ����֣��");
	names.push_back("������� ������");
	names.push_back("�������� ����ʩ��"); 
	names.push_back("�ײ��ϻ� ��κ�ս�");
	names.push_back("��л���� ��ˮ���"); 
	names.push_back("�����˸� �ɷ�����"); 
	names.push_back("³Τ���� ��ﻨ��"); 
	names.push_back("����Ԭ�� �ᱫʷ��"); 
	names.push_back("�����Ѧ �׺�����"); 
	names.push_back("�����ޱ� ��������"); 
	names.push_back("����ʱ�� Ƥ���뿵"); 
	names.push_back("����Ԫ�� ����ƽ��"); 
	names.push_back("�������� Ҧ��տ��"); 
	names.push_back("��ë��� �ױ����"); 
	names.push_back("�Ʒ��ɴ� ̸��é��"); 
	names.push_back("�ܼ����� ��ף����"); 
	names.push_back("�������� ϯ����ǿ"); 
	names.push_back("��·¦Σ ��ͯ�չ�"); 
	names.push_back("÷ʢ�ֵ� ��������"); 
	names.push_back("���Ĳ��� �������"); 
	names.push_back("����֧�� �ù�¬Ī"); 
	names.push_back("�������� �ɽ�Ӧ��"); 
	names.push_back("�����ڵ� ��������"); 
	names.push_back("������ʯ �޼�ť��"); 
	names.push_back("�����ϻ� ��½����"); 
	names.push_back("����춻� ����ҷ�"); 
	names.push_back("���ഢ�� ��������"); 
	names.push_back("���θ��� �ڽ��͹�"); 
	names.push_back("����ɽ�� �������"); 
	names.push_back("ȫۭ���� ��������"); 
	names.push_back("�����ﱩ ��������"); 
	names.push_back("������� ��ղ����"); 
	names.push_back("Ҷ��˾�� ۬�輻��"); 
	names.push_back("ӡ�ް׻� ��ۢ�Ӷ�"); 
	names.push_back("���̼��� ׿������"); 
	names.push_back("�������� ���ܲ�˫"); 
	names.push_back("��ݷ���� ̷���ͷ�"); 
	names.push_back("������� Ƚ��۪Ӻ"); 
	names.push_back("�S�ɣ�� �ţ��ͨ"); 
	names.push_back("�����༽ ۣ����ũ"); 
	names.push_back("�±�ׯ�� �����ֳ�"); 
	names.push_back("Ľ����ϰ �°�����"); 
	names.push_back("������� ��������"); 
	names.push_back("�߾Ӻⲽ ��������"); 
	names.push_back("����Ŀ� ��»�ڶ�"); 
	names.push_back("ŷ����� εԽ��¡"); 
	names.push_back("ʦ������ �˹�����"); 
	names.push_back("�������� �Ǽ��Ŀ�"); 
	names.push_back("����ɳؿ �������"); 
	names.push_back("�������� ��󾣺�"); 
	names.push_back("����Ȩ�� ���滸��"); 
	names.push_back("��ٹ˾�� �Ϲ�ŷ��"); 
	names.push_back("�ĺ���� ���˶���"); 
	names.push_back("�����ʸ� ξ�ٹ���"); 
	names.push_back("�̨��ұ �������");
	names.push_back("���ڵ��� ̫������"); 
	names.push_back("�������� ��ԯ���"); 
	names.push_back("�������� ����Ľ��"); 
	names.push_back("˾ͽ˾�� �ټ�����");

	// names.push_back("ξ����� ̫��");

	for (int i=0; i<names.size(); i++) {
		std::string utf8_name = ansi2utf8(names.at(i));
		char inbuf[1024] = {0};
		strcpy(inbuf, utf8_name.c_str());

		char outbuf[4096] = {0};
		char overage_buff[7] = {0};

		int add_blank = 1;
		int polyphone_support = 1;
		int first_letter_only = 0;
		int convert_double_char = 0;

		if (!is_utf8_string(inbuf)) {
			printf("File encoding is not utf-8!\n");
			return -1;
		}

		// printf("No:%d ", i);
		// printf("No:%d name:%s", names.at(i).c_str());
		utf8_to_pinyin(inbuf,
			outbuf,
			first_letter_only,
			polyphone_support,
			add_blank,
			convert_double_char,
			overage_buff);
		printf("\n");

		printf("No:%d name:%s, pinyin:%s",i, names.at(i).c_str(), outbuf);
	}
}