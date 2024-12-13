#include "pch.h"
#include "Game.h"
#include "Robot.h"
#include <Windows.h>
#include <mmsystem.h>
using namespace std;
Game::Game()
{
	thietlap();
}
void Game::vehinh(CClientDC* pdc)
{
	CString strdiem;
	strdiem.Format(_T("Score : %d    "), diem);
	pdc->TextOutW(100, 20, strdiem);
	nl.vehinh(pdc);
	dc.vehinh(pdc);
	rb.vehinh(pdc);
}
int Game::bamnut(CClientDC* pdc, CPoint p)
{
	if (nl.bamnutlenh(p) == 1 && nl.giatri == 0)
	{
		thietlap();
		nl.giatri = 1;
		nl.nd.Format(_T("stop"));
		nl.vehinh(pdc);
		dk = 1;
		return 1;
	}
	else
		if (nl.bamnutlenh(p) == 1 && nl.giatri == 1)
		{
			nl.giatri = 0;
			nl.nd.Format(_T("start"));
			nl.vehinh(pdc);
			dk = 0;
			return 0;
		}

}

void Game::vatcanchay(CClientDC* pdc)
{
	while (dk == 1)
	{
		diem++;
		dc.chay();
		Sleep(20);
	}


}

void Game::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		CString strdiem;
		strdiem.Format(_T("Score:%d      "), diem);
		pdc->TextOutW(100, 20, strdiem);
		diem++;
		dc.vehinh(pdc);
		rb.vehinh(pdc);
		if (dc.chamrobot(rb) == 1)
		{
			
			dk = 0;
			thang = -1;
			nl.giatri = 0;
			nl.nd.Format(_T("Start"));
			nl.vehinh(pdc);
			PlaySound(TEXT("C:\\Users\\PC\\Downloads\\gameover"), NULL, SND_NOWAIT);
			MessageBox(NULL, _T("             G  A  M  E  O  V  E  R  "), _T("info"), MB_OK) ;
		}
		Sleep(20);

	}

}

void Game::robotnhay()
{
	rb.nhaylen();
	
}

void Game::thietlap()
{
	CString str;
	str.Format(_T("start"));
	nl = Nutlenh(30, 20, str);
	dc = Duongchay();
	rb = Robot(200, dc.duongvien.y2 - 70);
	dk = 0;
	thang = 0;
	diem = 0;
}