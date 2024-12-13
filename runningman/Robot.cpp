#include "pch.h"
#include "Robot.h"
Robot::Robot()
{
    int mx = 0, my = 0;
    dau = Hcn(mx - 10, my - 20, mx + 10, my);
    mat = Hcn(mx - 5, my - 18, mx + 5, my - 10);
    than = Hcn(mx - 15, my, mx + 15, my + 50);
    chanTruoc = Hcn(mx - 15, my + 50, mx - 5, my + 70);
    chanSau = Hcn(mx + 5, my + 50, mx + 15, my + 70);
}

Robot::Robot(int mx, int my)
{
    dau = Hcn(mx - 10, my - 20, mx + 10, my);
    mat = Hcn(mx - 5, my - 18, mx + 5, my - 10);
    than = Hcn(mx - 15, my, mx + 15, my + 50);
    chanTruoc = Hcn(mx - 15, my + 50, mx - 5, my + 70);
    chanSau = Hcn(mx + 5, my + 50, mx + 15, my + 70);
}

void Robot::vehinh(CClientDC* pdc)
{
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
    dau.vehinh(pdc);
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
    mat.vehinh(pdc);
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
    than.vehinh(pdc);
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
    chanTruoc.vehinh(pdc);
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
    chanSau.vehinh(pdc);
}

void Robot::nhaylen()
{
    int i = 0;
    
    for (i = 0; i < 20; i++)
    {
        than.dichlen();
        mat.dichlen();
        dau.dichlen();
        chanTruoc.dichlen();
        chanSau.dichlen();
        Sleep(30);
    }
    
    for (i = 0; i < 20; i++)
    {
        than.dichxuong();
        mat.dichxuong();
        dau.dichxuong();
        chanTruoc.dichxuong();
        chanSau.dichxuong();
        Sleep(30);
      

    }
}