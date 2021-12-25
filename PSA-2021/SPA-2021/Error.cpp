#include "stdafx.h"
#include "Error.h"

Error::ERROR errors[ERROR_MAX_ENTRY] =
{
	ERROR_ENTRY(0, "������������ ��� ������"),
	ERROR_ENTRY(1, "C�������� ����"),
	ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
	ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),

	ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
	ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),

	ERROR_ENTRY(100, "�������� -in ������ ���� �����"),
	ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
	ERROR_ENTRY(104, "��������� ����� �������� ���������"),
	ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
	ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),

	ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
	ERROR_ENTRY(111, "������������ ������ � �������� ����� (-in)"),
	ERROR_ENTRY(112, "������ ��� �������� ����� ��������� (-log)"),
	ERROR_ENTRY(113, "������ ��� �������� ����� ������ (-out)"),
	ERROR_ENTRY_NODEF(114),
	ERROR_ENTRY_NODEF(115),
	ERROR_ENTRY_NODEF(116),
	ERROR_ENTRY_NODEF(117),
	ERROR_ENTRY_NODEF(118),
	ERROR_ENTRY_NODEF(119),

	ERROR_ENTRY(120, "[�����������] �������� ������������ ������ ������� ������"),
	ERROR_ENTRY(121, "[�����������] ������� ������ �����������"),
	ERROR_ENTRY(122, "[�����������] ��������������� �������"),
	ERROR_ENTRY(123, "[�����������] ����� �� ������� ������� ������"),
	ERROR_ENTRY(124, "[�����������] ��������� ����� ��������� ��������"),
	ERROR_ENTRY(125, "[�����������] �������� ������������ ������ ������� ���������������"),
	ERROR_ENTRY(126, "[�����������] ������� ��������������� �����������"),
	ERROR_ENTRY(127, "[�����������] ����� �� ������� ������� ���������������"),
	ERROR_ENTRY(128, "[�����������] ��������� ���������� main"),
	ERROR_ENTRY(129, "[�����������] ���������� ������� ����� ��������� ������� main"),
	ERROR_ENTRY(130, "[�����������] ��������� �������� �������������� ��������"),
	ERROR_ENTRY(131, "[�����������] ������������ ���������� �������� �������"),
	ERROR_ENTRY(132, "[�����������] ���������� ���� PINT ������� �� ����� ����������� ��������"),
	ERROR_ENTRY(133, "[�����������] ������ ������(��������� ������������ ��� �������� � �������)"),
	ERROR_ENTRY(134, "[�����������] ������ ������������ ������ �����������"), 
	ERROR_ENTRY_NODEF(135), ERROR_ENTRY_NODEF(136),
	ERROR_ENTRY_NODEF(137), ERROR_ENTRY_NODEF(138), ERROR_ENTRY_NODEF(139),
	ERROR_ENTRY_NODEF10(140),
	ERROR_ENTRY_NODEF10(150),
	ERROR_ENTRY_NODEF10(160),
	ERROR_ENTRY_NODEF10(170),
	ERROR_ENTRY_NODEF10(180),
	ERROR_ENTRY_NODEF10(190),

	ERROR_ENTRY_NODEF100(200),

	ERROR_ENTRY(300, "[C������������] ������� main ������ ���������� �������� ��������"),
	ERROR_ENTRY(301, "[C������������] ��� ������� � ��� ������������� �������� ����������"),
	ERROR_ENTRY(302, "[C������������] �������� ���������� ��� �������������� ����� ���������� � ���������� �������"),
	ERROR_ENTRY(303, "[C������������] "),
	ERROR_ENTRY(304, "[C������������] ��������� ����������� �������� �������"),
	ERROR_ENTRY(305, "[C������������] ������������� ������������ ���� ������(������� ��������� ���� ������ � ���������)"),
	ERROR_ENTRY(306, "[C������������] ������������� ����� ���������� � �������� �������"),
	ERROR_ENTRY(307, "[C������������] ������������� �������������"),
	ERROR_ENTRY(308, "[C������������] ������� ��������������� ��������������"),
	ERROR_ENTRY(310, "[C������������] �������� ��������� ������������ �����"),
	ERROR_ENTRY(311, "[C������������] ������������ �������� ��� ������ �����"),
	ERROR_ENTRY(312, "[C������������] ������������ �������� ���������� ���� PINT"),
	ERROR_ENTRY(313, "[C������������] ������� �������� ������ ���� ������"),
	ERROR_ENTRY(314, "[C������������] ������������ �������� ���������� ���� PSTRING"),
	ERROR_ENTRY(315, "[C������������] �������� ����� ����������� ���������"),
	ERROR_ENTRY_NODEF(316),
	ERROR_ENTRY_NODEF(317),
	ERROR_ENTRY_NODEF(318),
	ERROR_ENTRY_NODEF(319),
	ERROR_ENTRY_NODEF10(320),
	ERROR_ENTRY_NODEF10(330),
	ERROR_ENTRY_NODEF10(340),
	ERROR_ENTRY_NODEF10(350),
	ERROR_ENTRY_NODEF10(360),
	ERROR_ENTRY_NODEF10(370),
	ERROR_ENTRY_NODEF10(380),
	ERROR_ENTRY_NODEF10(390),

	ERROR_ENTRY_NODEF100(400),

	ERROR_ENTRY_NODEF100(500),

	ERROR_ENTRY(600, "[��������������] �������� ��������� ���������"),
	ERROR_ENTRY(601, "[��������������] �� ������ ������ ���������� �������"),
	ERROR_ENTRY(602, "[��������������] ������ � ���� �������"),
	ERROR_ENTRY(603, "[��������������] ������ � ���� ���������"),
	ERROR_ENTRY(604, "[��������������] ������ � ������ ���������� �������"),
	ERROR_ENTRY(605, "[��������������] ������ � ������ �������/���������"),
	ERROR_ENTRY(606, "[��������������] ������ � ������ ����������� ���������� �������"),
	ERROR_ENTRY(607, "[��������������] ������ � ������� ��������� ���������"),
	ERROR_ENTRY(608, "[��������������] �������� �������� ��������"),
	ERROR_ENTRY(609, "[��������������] �������� �������������� ��������"),
	ERROR_ENTRY(610, "[��������������] �������� ���������. ��������� ������ ��������������/��������"),
	ERROR_ENTRY(611, "[��������������] ������ � �������������� ���������"),
	ERROR_ENTRY(612, "[��������������] ������������ �������������� �����������"),
	ERROR_ENTRY(613, "[��������������] �������������� ������ �������� � �������"),
	ERROR_ENTRY_NODEF(614),
	ERROR_ENTRY_NODEF(615),
	ERROR_ENTRY_NODEF(616),
	ERROR_ENTRY_NODEF(617),
	ERROR_ENTRY_NODEF(618),
	ERROR_ENTRY_NODEF(619),
	ERROR_ENTRY_NODEF10(620),
	ERROR_ENTRY_NODEF10(630),
	ERROR_ENTRY_NODEF10(640),
	ERROR_ENTRY_NODEF10(650),
	ERROR_ENTRY_NODEF10(660),
	ERROR_ENTRY_NODEF10(670),
	ERROR_ENTRY_NODEF10(680),
	ERROR_ENTRY_NODEF10(690),

	ERROR_ENTRY_NODEF100(700),

	ERROR_ENTRY_NODEF100(800),

	ERROR_ENTRY_NODEF100(900)
};


Error::ERROR Error::geterror(int id)
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		return errors[id];
	}
	return errors[0];
}

Error::ERROR Error::geterrorin(int id, int line, int column)
{
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->place = { (short)line, (short)column };
		return *temp;
	}
	return errors[0];
}

Error::ERROR Error::geterrorword(int id, int line, std::string word) {
	if ((0 < id) && (id < ERROR_MAX_ENTRY)) {
		Error::ERROR* temp = &errors[id];
		temp->word = { (short)line, word };
		return *temp;
	}
	return errors[0];
}