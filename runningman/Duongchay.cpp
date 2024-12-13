#include "pch.h"
#include "Duongchay.h"

Duongchay::Duongchay()
{
    duongvien = Hcn(XDAU, YDAU, XDAU + 1917, YDAU + 400);
    int a[5] = { 20, 15, 25, 28, 31 };
    int dist = 400;
    int offset = 0;

    for (int i = 0; i < 5; i++)
    {
        vatcan[i] = Hcn(XDAU + 50 + i * dist + offset, duongvien.y2 - a[i], XDAU + 60 + i * dist + offset, duongvien.y2);
        offset += 10 ;
    }
    for (int i = 0; i < 3; i++)
    {
        clouds[i] = Hcn(XDAU + 150 + i * dist * 2, YDAU + 50, XDAU + 200 + i * dist * 2, YDAU + 100);
    }
}

void Duongchay::vehinh(CClientDC* pdc)
{
    pdc->SelectObject(GetStockObject(BLACK_BRUSH));
    duongvien.vehinh(pdc);
    pdc->SelectObject(GetStockObject(GRAY_BRUSH));
    for (int i = 0; i < 5; i++)
        vatcan[i].vehinh(pdc);
    for (int i = 0; i < 3; i++)
        clouds[i].vehinh(pdc);
    pdc->SelectObject(GetStockObject(WHITE_BRUSH));
   

}

void Duongchay::chay()
{
    for (int i = 0; i < 5; i++)
    {
        vatcan[i].dichtrai();
        if (vatcan[i].x1 < duongvien.x1)
        {
            vatcan[i].x1 = duongvien.x2 - 10;
            vatcan[i].x2 = duongvien.x2;
            vatcan[i].y1 = duongvien.y2 - (rand() % 30 + 15);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        clouds[i].dichtrai();
        if (clouds[i].x1 < duongvien.x1)
        {
            clouds[i].x1 = duongvien.x2 - 60;
            clouds[i].x2 = duongvien.x2;
        }
    }

}

int Duongchay::chamrobot(Robot rb)
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        if (vatcan[i].ktgiaonhau(rb.dau) == 1 || vatcan[i].ktgiaonhau(rb.than) == 1 || vatcan[i].ktgiaonhau(rb.chanTruoc) == 1 || vatcan[i].ktgiaonhau(rb.chanSau) == 1 || vatcan[i].ktgiaonhau(rb.mat) == 1)
            return 1;
    }
    return 0;
}