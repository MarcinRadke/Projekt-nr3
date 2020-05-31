#pragma once
#include "Gra.h"
#include <iostream>
/*
 *  realizuje gre w kolko i krzyzyk z komputerem
 *  czlowiek jest 'X'
 */
void GraPvC_Krzyzyk();

/*
 *  realizuje gre w kolko i krzyzyk z komputerem
 *  czlowiek jest 'O'
 */
void GraPvC_Kolko();

/*
 *  realizuje gre w kolko i krzyzyk
 */
void GraPvP();

/*
 *  wyswietla menu nawigacyjne
 */
void pokazMenu();

void Testy();

/*
 *  glowna funckja realizujaca gre, umozliwia wybor trybu
 */
void FinalnaGra();
