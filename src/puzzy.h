#pragma once
#include "Fuzzy.h"

Fuzzy *fuzzy = new Fuzzy();

typedef struct
{
  void begin();
  bool setinput(int index, float input);
  bool fuzify();
  int output();
} FuzzyHandler;

void FuzzyHandler::begin()
{
  // Fuzzy Input 1 DO
  FuzzyInput *DO = new FuzzyInput(1);
  FuzzySet *DO_Rendah = new FuzzySet(0, 0, 2, 4);
  DO->addFuzzySet(DO_Rendah);
  FuzzySet *DO_Normal = new FuzzySet(3, 5, 6, 8);
  DO->addFuzzySet(DO_Normal);
  FuzzySet *DO_Banyak = new FuzzySet(7, 9, 10, 10);
  DO->addFuzzySet(DO_Banyak);
  fuzzy->addFuzzyInput(DO);

// Fuzzy Input 2 pH
  FuzzyInput *pH = new FuzzyInput(1);
  FuzzySet *pH_Rendah = new FuzzySet(0, 0, 4, 5);
  pH->addFuzzySet(pH_Rendah);
  FuzzySet *pH_Normal = new FuzzySet(4, 5, 7, 8);
  pH->addFuzzySet(pH_Normal);
  FuzzySet *pH_Banyak = new FuzzySet(7, 8, 12, 12);
  pH->addFuzzySet(pH_Banyak);
  fuzzy->addFuzzyInput(pH);

// Fuzzy Input 3 Suhu
  FuzzyInput *Suhu = new FuzzyInput(1);
  FuzzySet *Suhu_Rendah = new FuzzySet(0, 0, 25, 28);
  Suhu->addFuzzySet(Suhu_Rendah);
  FuzzySet *Suhu_Normal = new FuzzySet(27, 29, 31, 33);
  Suhu->addFuzzySet(Suhu_Normal);
  FuzzySet *Suhu_Banyak = new FuzzySet(32, 35, 100, 100);
  Suhu->addFuzzySet(Suhu_Banyak);
  fuzzy->addFuzzyInput(Suhu);

// Fuzzy Input 4 Kekeruhan
  FuzzyInput *Kekeruhan = new FuzzyInput(1);
  FuzzySet *Kekeruhan_Rendah = new FuzzySet(0, 0, 25, 55);
  Kekeruhan->addFuzzySet(Kekeruhan_Rendah);
  FuzzySet *Kekeruhan_Normal = new FuzzySet(45, 75, 75, 105);
  Kekeruhan->addFuzzySet(Kekeruhan_Normal);
  FuzzySet *Kekeruhan_Banyak = new FuzzySet(95, 125, 250, 250);
  Kekeruhan->addFuzzySet(Kekeruhan_Banyak);
  fuzzy->addFuzzyInput(Kekeruhan);

// Fuzzy Input 5 Jarak
  FuzzyInput *Jarak = new FuzzyInput(1);
  FuzzySet *Jarak_Dangkal = new FuzzySet(0, 0, 30, 70);
  Jarak->addFuzzySet(Jarak_Dangkal);
  FuzzySet *Jarak_Sedang = new FuzzySet(50, 70, 80, 100);
  Jarak->addFuzzySet(Jarak_Sedang);
  FuzzySet *Jarak_Dalam = new FuzzySet(80, 120, 150, 150);
  Jarak->addFuzzySet(Jarak_Dalam);
  fuzzy->addFuzzyInput(Jarak);

// Fuzzy Input 6 EC
  FuzzyInput *EC = new FuzzyInput(1);
  FuzzySet *EC_Rendah = new FuzzySet(0, 0, 10, 15);
  EC->addFuzzySet(EC_Rendah);
  FuzzySet *EC_Normal = new FuzzySet(10, 15, 20, 25);
  EC->addFuzzySet(EC_Normal);
  FuzzySet *EC_Tinggi = new FuzzySet(20, 30, 100, 100);
  EC->addFuzzySet(EC_Tinggi);
  fuzzy->addFuzzyInput(EC);  

// Fuzzy Output
  FuzzyOutput *Notif = new FuzzyOutput(1);
  FuzzySet *Aman = new FuzzySet(0, 0, 0, 0);
  Notif->addFuzzySet(Aman);
  FuzzySet *Ganti = new FuzzySet(1, 1, 1, 1);
  Notif->addFuzzySet(Ganti);
  fuzzy->addFuzzyOutput(Notif);

  // Rule 1
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah1 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah1->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah1  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah1->joinWithAND(DO_Rendah_pH_Rendah1, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah1  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah1->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah1, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal1  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal1->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah1, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah1  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah1->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal1, EC_Rendah);
  FuzzyRuleConsequent *Ganti1 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule1 = new FuzzyRule(1,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah1, Ganti1);
  fuzzy->addFuzzyRule(fuzzyRule1);

  // Rule 2
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah2 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah2->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah2  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah2->joinWithAND(DO_Rendah_pH_Rendah2, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah2  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah2->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah2, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal2  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal2->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah2, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal2  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal2->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal2, EC_Normal);
  FuzzyRuleConsequent *Ganti2 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule2 = new FuzzyRule(2,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal2, Ganti2);
  fuzzy->addFuzzyRule(fuzzyRule2);

  // Rule 3
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah3 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah3->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah3  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah3->joinWithAND(DO_Rendah_pH_Rendah3, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah3 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah3->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah3, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal3  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal3->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah3, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi3  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi3->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal3, EC_Tinggi);
  FuzzyRuleConsequent *Ganti3 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule3 = new FuzzyRule(3,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi3, Ganti3);
  fuzzy->addFuzzyRule(fuzzyRule3);

  // Rule 4
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah4 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah4->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah4 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah4->joinWithAND(DO_Rendah_pH_Rendah4, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah4 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah4->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah4, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang4 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang4->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah4, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah4  = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah4->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang4, EC_Rendah);
  FuzzyRuleConsequent *Ganti4 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule4 = new FuzzyRule(4,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah4, Ganti4);
  fuzzy->addFuzzyRule(fuzzyRule4);

  // Rule 5
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah5 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah5->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah5 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah5->joinWithAND(DO_Rendah_pH_Rendah5, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah5 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah5->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah5, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang5 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang5->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah5, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal5 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal5->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang5, EC_Normal);
  FuzzyRuleConsequent *Ganti5 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule5 = new FuzzyRule(5,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal5, Ganti5);
  fuzzy->addFuzzyRule(fuzzyRule5);

  // Rule 6
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah6 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah6->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah6 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah6->joinWithAND(DO_Rendah_pH_Rendah6, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah6 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah6->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah6, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang6 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang6->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah6, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi6 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi6->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang6, EC_Tinggi);
  FuzzyRuleConsequent *Ganti6 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule6 = new FuzzyRule(6,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi6, Ganti6);
  fuzzy->addFuzzyRule(fuzzyRule6);

  // Rule 7
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah7 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah7->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah7 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah7->joinWithAND(DO_Rendah_pH_Rendah7, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah7 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah7->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah7, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam7 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam7->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah7, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah7 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah7->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam7, EC_Rendah);
  FuzzyRuleConsequent *Ganti7 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule7 = new FuzzyRule(7,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah7, Ganti7);
  fuzzy->addFuzzyRule(fuzzyRule7);

  // Rule 8
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah8 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah8->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah8 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah8->joinWithAND(DO_Rendah_pH_Rendah8, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah8 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah8->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah8, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam8 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam8->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah8, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal8 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal8->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam8, EC_Normal);
  FuzzyRuleConsequent *Ganti8 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule8 = new FuzzyRule(8,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal8, Ganti8);
  fuzzy->addFuzzyRule(fuzzyRule8);

  // Rule 9
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah9 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah9->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah9 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah9->joinWithAND(DO_Rendah_pH_Rendah9, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah9 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah9->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah9, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam9 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam9->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah9, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi9 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi9->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam9, EC_Tinggi);
  FuzzyRuleConsequent *Ganti9 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule9 = new FuzzyRule(9,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi9, Ganti9);
  fuzzy->addFuzzyRule(fuzzyRule9);

  // Rule 10
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah10 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah10->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah10 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah10->joinWithAND(DO_Rendah_pH_Rendah10, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal10 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal10->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah10, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal10 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal10->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal10, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah10 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah10->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal10, EC_Rendah);
  FuzzyRuleConsequent *Ganti10 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule10 = new FuzzyRule(10,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah10, Ganti10);
  fuzzy->addFuzzyRule(fuzzyRule10);
  
  // Rule 11
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah11 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah11->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah11 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah11->joinWithAND(DO_Rendah_pH_Rendah11, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal11 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal11->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah11, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal11 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal11->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal11, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal11 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal11->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal11, EC_Normal);
  FuzzyRuleConsequent *Ganti11 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule11 = new FuzzyRule(11,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal11, Ganti11);
  fuzzy->addFuzzyRule(fuzzyRule11);

  // Rule 12
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah12 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah12->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah12 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah12->joinWithAND(DO_Rendah_pH_Rendah12, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal12 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal12->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah12, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal12 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal12->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal12, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi12 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi12->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal12, EC_Tinggi);
  FuzzyRuleConsequent *Ganti12 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule12 = new FuzzyRule(12,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi12, Ganti12);
  fuzzy->addFuzzyRule(fuzzyRule12);

  // Rule 13
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah13 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah13->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah13 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah13->joinWithAND(DO_Rendah_pH_Rendah13, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal13 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal13->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah13, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang13 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang13->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal13, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah13 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah13->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang13, EC_Rendah);
  FuzzyRuleConsequent *Ganti13 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule13 = new FuzzyRule(13,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah13, Ganti13);
  fuzzy->addFuzzyRule(fuzzyRule13);

  // Rule 14
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah14 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah14->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah14 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah14->joinWithAND(DO_Rendah_pH_Rendah14, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal14 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal14->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah14, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang14 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang14->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal14, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal14 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal14->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang14, EC_Normal);
  FuzzyRuleConsequent *Ganti14 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule14 = new FuzzyRule(14,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal14, Ganti14);
  fuzzy->addFuzzyRule(fuzzyRule14);

  // Rule 15
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah15 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah15->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah15 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah15->joinWithAND(DO_Rendah_pH_Rendah15, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal15 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal15->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah15, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang15 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang15->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal15, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi15 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi15->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang15, EC_Tinggi);
  FuzzyRuleConsequent *Ganti15 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule15 = new FuzzyRule(15,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi15, Ganti15);
  fuzzy->addFuzzyRule(fuzzyRule15);

  // Rule 16
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah16 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah16->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah16 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah16->joinWithAND(DO_Rendah_pH_Rendah16, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal16 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal16->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah16, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam16 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam16->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal16, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah16 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah16->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam16, EC_Rendah);
  FuzzyRuleConsequent *Ganti16 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule16 = new FuzzyRule(16,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah16, Ganti16);
  fuzzy->addFuzzyRule(fuzzyRule16);

  // Rule 17
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah17 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah17->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah17 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah17->joinWithAND(DO_Rendah_pH_Rendah17, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal17 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal17->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah17, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam17 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam17->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal17, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal17 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal17->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam17, EC_Normal);
  FuzzyRuleConsequent *Ganti17 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule17 = new FuzzyRule(17,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal17, Ganti17);
  fuzzy->addFuzzyRule(fuzzyRule17);

  // Rule 18
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah18 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah18->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah18 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah18->joinWithAND(DO_Rendah_pH_Rendah18, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal18 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal18->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah18, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam18 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam18->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal18, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi18 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi18->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam18, EC_Tinggi);
  FuzzyRuleConsequent *Ganti18 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule18 = new FuzzyRule(18,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi18, Ganti18);
  fuzzy->addFuzzyRule(fuzzyRule18);

  // Rule 19
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah19 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah19->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah19 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah19->joinWithAND(DO_Rendah_pH_Rendah19, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak19 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak19->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah19, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal19 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal19->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak19, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah19 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah19->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal19, EC_Rendah);
  FuzzyRuleConsequent *Ganti19 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule19 = new FuzzyRule(19,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah19, Ganti19);
  fuzzy->addFuzzyRule(fuzzyRule19);

  // Rule 20
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah20 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah20->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah20 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah20->joinWithAND(DO_Rendah_pH_Rendah20, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak20 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak20->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah20, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal20 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal20->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak20, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal20 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal20->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal20, EC_Normal);
  FuzzyRuleConsequent *Ganti20 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule20 = new FuzzyRule(20,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal20, Ganti20);
  fuzzy->addFuzzyRule(fuzzyRule20);

  // Rule 21
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah21 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah21->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah21 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah21->joinWithAND(DO_Rendah_pH_Rendah21, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak21 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak21->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah21, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal21 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal21->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak21, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi21 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi21->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal21, EC_Tinggi);
  FuzzyRuleConsequent *Ganti21 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule21 = new FuzzyRule(21,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi21, Ganti21);
  fuzzy->addFuzzyRule(fuzzyRule21);

  // Rule 22
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah22 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah22->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah22 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah22->joinWithAND(DO_Rendah_pH_Rendah22, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak22 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak22->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah22, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang22 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang22->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak22, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah22 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah22->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang22, EC_Rendah);
  FuzzyRuleConsequent *Ganti22 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule22 = new FuzzyRule(22,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah22, Ganti22);
  fuzzy->addFuzzyRule(fuzzyRule22);

  // Rule 23
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah23 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah23->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah23 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah23->joinWithAND(DO_Rendah_pH_Rendah23, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak23 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak23->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah23, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang23 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang23->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak23, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal23 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal23->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang23, EC_Normal);
  FuzzyRuleConsequent *Ganti23 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule23 = new FuzzyRule(23,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal23, Ganti23);
  fuzzy->addFuzzyRule(fuzzyRule23);

  // Rule 24
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah24 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah24->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah24 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah24->joinWithAND(DO_Rendah_pH_Rendah24, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak24 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak24->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah24, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang24 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang24->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak24, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi24 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi24->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang24, EC_Tinggi);
  FuzzyRuleConsequent *Ganti24 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule24 = new FuzzyRule(24,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi24, Ganti24);
  fuzzy->addFuzzyRule(fuzzyRule24);

  // Rule 25
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah25 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah25->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah25 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah25->joinWithAND(DO_Rendah_pH_Rendah25, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak25 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak25->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah25, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam25 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam25->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak25, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah25 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah25->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam25, EC_Rendah);
  FuzzyRuleConsequent *Ganti25 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule25 = new FuzzyRule(25,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah25, Ganti25);
  fuzzy->addFuzzyRule(fuzzyRule25);

  // Rule 26
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah26 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah26->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah26 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah26->joinWithAND(DO_Rendah_pH_Rendah26, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak26 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak26->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah26, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam26 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam26->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak26, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal26 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal26->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam26, EC_Normal);
  FuzzyRuleConsequent *Ganti26 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule26 = new FuzzyRule(26,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal26, Ganti26);
  fuzzy->addFuzzyRule(fuzzyRule26);

  // Rule 27
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah27 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah27->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah27 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah27->joinWithAND(DO_Rendah_pH_Rendah27, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak27 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak27->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah27, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam27 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam27->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak27, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi27 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi27->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam27, EC_Tinggi);
  FuzzyRuleConsequent *Ganti27 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule27 = new FuzzyRule(27,DO_Rendah_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi27, Ganti27);
  fuzzy->addFuzzyRule(fuzzyRule27);

  // Rule 28
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah28 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah28->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal28 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal28->joinWithAND(DO_Rendah_pH_Rendah28, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah28 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah28->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal28, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal28 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal28->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah28, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah28 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah28->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal28, EC_Rendah);
  FuzzyRuleConsequent *Ganti28 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule28 = new FuzzyRule(28,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah28, Ganti28);
  fuzzy->addFuzzyRule(fuzzyRule28);

  // Rule 29
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah29 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah29->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal29 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal29->joinWithAND(DO_Rendah_pH_Rendah29, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah29 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah29->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal29, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal29 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal29->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah29, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal29 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal29->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal29, EC_Normal);
  FuzzyRuleConsequent *Ganti29 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule29 = new FuzzyRule(29,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal29, Ganti29);
  fuzzy->addFuzzyRule(fuzzyRule29);

  // Rule 30
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah30 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah30->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal30 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal30->joinWithAND(DO_Rendah_pH_Rendah30, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah30 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah30->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal30, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal30 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal30->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah30, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi30 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi30->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal30, EC_Tinggi);
  FuzzyRuleConsequent *Ganti30 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule30 = new FuzzyRule(30,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi30, Ganti30);
  fuzzy->addFuzzyRule(fuzzyRule30);

  // Rule 31
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah31 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah31->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal31 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal31->joinWithAND(DO_Rendah_pH_Rendah31, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah31 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah31->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal31, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang31 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang31->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah31, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah31 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah31->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang31, EC_Rendah);
  FuzzyRuleConsequent *Ganti31 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule31 = new FuzzyRule(31,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah31, Ganti31);
  fuzzy->addFuzzyRule(fuzzyRule31);

  // Rule 32
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah32 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah32->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal32 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal32->joinWithAND(DO_Rendah_pH_Rendah32, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah32 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah32->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal32, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang32 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang32->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah32, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal32 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal32->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang32, EC_Normal);
  FuzzyRuleConsequent *Ganti32 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule32 = new FuzzyRule(32,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal32, Ganti32);
  fuzzy->addFuzzyRule(fuzzyRule32);

  // Rule 33
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah33 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah33->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal33 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal33->joinWithAND(DO_Rendah_pH_Rendah33, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah33 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah33->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal33, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang33 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang33->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah33, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi33 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi33->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang33, EC_Tinggi);
  FuzzyRuleConsequent *Ganti33 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule33 = new FuzzyRule(33,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi33, Ganti33);
  fuzzy->addFuzzyRule(fuzzyRule33);

  // Rule 34
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah34 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah34->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal34 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal34->joinWithAND(DO_Rendah_pH_Rendah34, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah34 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah34->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal34, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam34 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam34 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah34, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah34 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah34->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam34, EC_Rendah);
  FuzzyRuleConsequent *Ganti34 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule34 = new FuzzyRule(34,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah34, Ganti34);
  fuzzy->addFuzzyRule(fuzzyRule34);

  // Rule 35
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah35 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah35->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal35 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal35->joinWithAND(DO_Rendah_pH_Rendah35, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah35 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah35->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal35, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam35 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam35 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah35, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal35 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal35->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam35, EC_Normal);
  FuzzyRuleConsequent *Ganti35 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule35 = new FuzzyRule(35,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal35, Ganti35);
  fuzzy->addFuzzyRule(fuzzyRule35);

  // Rule 36
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah36 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah36->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal36 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal36->joinWithAND(DO_Rendah_pH_Rendah36, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah36 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah36->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal36, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam36 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam36 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah36, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi36 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi36->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam36, EC_Tinggi);
  FuzzyRuleConsequent *Ganti36 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule36 = new FuzzyRule(36,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi36, Ganti36);
  fuzzy->addFuzzyRule(fuzzyRule36);

  // Rule 37
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah37 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah37->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal37 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal37->joinWithAND(DO_Rendah_pH_Rendah37, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal37 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal37->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal37, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal37 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal37->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal37, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah37 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah37 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal37, EC_Rendah);
  FuzzyRuleConsequent *Ganti37 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule37 = new FuzzyRule(37,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah37, Ganti37);
  fuzzy->addFuzzyRule(fuzzyRule37); 

  // Rule 38
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah38 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah38->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal38 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal38->joinWithAND(DO_Rendah_pH_Rendah38, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal38 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal38->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal38, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal38 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal38->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal38, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal38 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal38 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal38, EC_Normal);
  FuzzyRuleConsequent *Ganti38 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule38 = new FuzzyRule(38,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal38, Ganti38);
  fuzzy->addFuzzyRule(fuzzyRule38);

  // Rule 39
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah39 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah39->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal39 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal39->joinWithAND(DO_Rendah_pH_Rendah39, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal39 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal39->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal39, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal39 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal39->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal39, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi39 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi39 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal39, EC_Tinggi);
  FuzzyRuleConsequent *Ganti39 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule39 = new FuzzyRule(39,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi39, Ganti39);
  fuzzy->addFuzzyRule(fuzzyRule39);

  // Rule 40
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah40 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah40->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal40 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal40->joinWithAND(DO_Rendah_pH_Rendah40, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal40 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal40->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal40, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang40 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang40->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal40, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah40 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah40 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang40, EC_Rendah);
  FuzzyRuleConsequent *Ganti40 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule40 = new FuzzyRule(40,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah40, Ganti40);
  fuzzy->addFuzzyRule(fuzzyRule40);

  // Rule 41
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah41 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah41->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal41 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal41->joinWithAND(DO_Rendah_pH_Rendah41, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal41 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal41->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal41, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang41 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang41->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal41, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal41 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal41 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang41, EC_Normal);
  FuzzyRuleConsequent *Ganti41 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule41 = new FuzzyRule(41,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal41, Ganti41);
  fuzzy->addFuzzyRule(fuzzyRule41);

  // Rule 42
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah42 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah42->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal42 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal42->joinWithAND(DO_Rendah_pH_Rendah42, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal42 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal42->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal42, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang42 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang42->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal42, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi42 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi42 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang42, EC_Tinggi);
  FuzzyRuleConsequent *Ganti42 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule42 = new FuzzyRule(42,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi42, Ganti42);
  fuzzy->addFuzzyRule(fuzzyRule42);

  // Rule 43
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah43 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah43->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal43 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal43->joinWithAND(DO_Rendah_pH_Rendah43, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal43 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal43->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal43, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam43 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam43->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal43, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah43 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah43 ->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam43, EC_Rendah);
  FuzzyRuleConsequent *Ganti43 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule43 = new FuzzyRule(43,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah43, Ganti43);
  fuzzy->addFuzzyRule(fuzzyRule43);

  // Rule 44
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah44 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah44->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal44 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal44->joinWithAND(DO_Rendah_pH_Rendah44, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal44 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal44->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal44, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam44 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam44->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal44, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal44 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal44->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam44, EC_Normal);
  FuzzyRuleConsequent *Ganti44 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule44 = new FuzzyRule(44,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal44, Ganti44);
  fuzzy->addFuzzyRule(fuzzyRule44);

  // Rule 45
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah45 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah45->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal45 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal45->joinWithAND(DO_Rendah_pH_Rendah45, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal45 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal45->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal45, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam45 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam45->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal45, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi45 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi45->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam45, EC_Tinggi);
  FuzzyRuleConsequent *Ganti45 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule45 = new FuzzyRule(45,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi45, Ganti45);
  fuzzy->addFuzzyRule(fuzzyRule45);

  // Rule 46
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah46 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah46->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal46 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal46->joinWithAND(DO_Rendah_pH_Rendah46, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak46 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak46->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal46, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal46 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal46->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak46, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah46 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah46->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal46, EC_Rendah);
  FuzzyRuleConsequent *Ganti46 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule46 = new FuzzyRule(46,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah46, Ganti46);
  fuzzy->addFuzzyRule(fuzzyRule46); 

  // Rule 47
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah47 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah47->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal47 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal47->joinWithAND(DO_Rendah_pH_Rendah47, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak47 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak47->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal47, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal47 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal47->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak47, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal47 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal47->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal47, EC_Normal);
  FuzzyRuleConsequent *Ganti47 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule47 = new FuzzyRule(47,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal47, Ganti47);
  fuzzy->addFuzzyRule(fuzzyRule47); 

  // Rule 48
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah48 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah48->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal48 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal48->joinWithAND(DO_Rendah_pH_Rendah48, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak48 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak48->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal48, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal48 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal48->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak48, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi48 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi48->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal48, EC_Tinggi);
  FuzzyRuleConsequent *Ganti48 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule48 = new FuzzyRule(48,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi48, Ganti48);
  fuzzy->addFuzzyRule(fuzzyRule48); 
  
  // Rule 49
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah49 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah49->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal49 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal49->joinWithAND(DO_Rendah_pH_Rendah49, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak49 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak49->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal49, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang49 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang49->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak49, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah49 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah49->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang49, EC_Rendah);
  FuzzyRuleConsequent *Ganti49 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule49 = new FuzzyRule(49,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah49, Ganti49);
  fuzzy->addFuzzyRule(fuzzyRule49);

  // Rule 50
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah50 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah50->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal50 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal50->joinWithAND(DO_Rendah_pH_Rendah50, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak50 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak50->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal50, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang50 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang50->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak50, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal50 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal50->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang50, EC_Normal);
  FuzzyRuleConsequent *Ganti50 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule50 = new FuzzyRule(50,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal50, Ganti50);
  fuzzy->addFuzzyRule(fuzzyRule50);

  // Rule 51
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah51 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah51->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal51 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal51->joinWithAND(DO_Rendah_pH_Rendah51, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak51 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak51->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal51, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang51 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang51->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak51, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi51 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi51->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang51, EC_Tinggi);
  FuzzyRuleConsequent *Ganti51 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule51 = new FuzzyRule(51,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi51, Ganti51);
  fuzzy->addFuzzyRule(fuzzyRule51);

  // Rule 52
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah52 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah52->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal52 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal52->joinWithAND(DO_Rendah_pH_Rendah52, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak52 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak52->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal52, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam52 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam52->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak52, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah52 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah52->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam52, EC_Rendah);
  FuzzyRuleConsequent *Ganti52 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule52 = new FuzzyRule(52,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah52, Ganti52);
  fuzzy->addFuzzyRule(fuzzyRule52);

  // Rule 53
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah53 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah53->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal53 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal53->joinWithAND(DO_Rendah_pH_Rendah53, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak53 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak53->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal53, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam53 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam53->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak53, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal53 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal53->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam53, EC_Normal);
  FuzzyRuleConsequent *Ganti53 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule53 = new FuzzyRule(53,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal53, Ganti53);
  fuzzy->addFuzzyRule(fuzzyRule53);

  // Rule 54
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah54 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah54->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal54 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal54->joinWithAND(DO_Rendah_pH_Rendah54, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak54 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak54->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal54, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam54 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam54->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak54, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi54 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi54->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam54, EC_Tinggi);
  FuzzyRuleConsequent *Ganti54 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule54 = new FuzzyRule(54,DO_Rendah_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi54, Ganti54);
  fuzzy->addFuzzyRule(fuzzyRule54);

  // Rule 55
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah55 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah54->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak55 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak55->joinWithAND(DO_Rendah_pH_Rendah55, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah55 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah55->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak55, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal55 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal55->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah55, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah55 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah55->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal55, EC_Rendah);
  FuzzyRuleConsequent *Ganti55 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule55 = new FuzzyRule(55,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah55, Ganti55);
  fuzzy->addFuzzyRule(fuzzyRule55);

  // Rule 56
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah56 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah56->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak56 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak56->joinWithAND(DO_Rendah_pH_Rendah56, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah56 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah56->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak56, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal56 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal56->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah56, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal56 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal56->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal56, EC_Normal);
  FuzzyRuleConsequent *Ganti56 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule56 = new FuzzyRule(56,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal56, Ganti56);
  fuzzy->addFuzzyRule(fuzzyRule56);

  // Rule 57
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah57 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah57->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak57 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak57->joinWithAND(DO_Rendah_pH_Rendah57, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah57 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah57->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak57, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal57 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal57->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah57, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi57 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi57->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal57, EC_Tinggi);
  FuzzyRuleConsequent *Ganti57 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule57 = new FuzzyRule(57,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi57, Ganti57);
  fuzzy->addFuzzyRule(fuzzyRule57);

  // Rule 58
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah58 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah58->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak58 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak58->joinWithAND(DO_Rendah_pH_Rendah58, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah58 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah58->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak58, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang58 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang58->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah58, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah58 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah58->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang58, EC_Rendah); 
  FuzzyRuleConsequent *Ganti58 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule58 = new FuzzyRule(58,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah58, Ganti58);
  fuzzy->addFuzzyRule(fuzzyRule58);

  // Rule 59
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah59 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah59->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak59 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak59->joinWithAND(DO_Rendah_pH_Rendah59, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah59 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah59->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak59, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang59 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang59->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah59, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal59 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal59->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang59, EC_Normal); 
  FuzzyRuleConsequent *Ganti59 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule59 = new FuzzyRule(59,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal59, Ganti59);
  fuzzy->addFuzzyRule(fuzzyRule59);

  // Rule 60
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah60 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah60->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak60 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak60->joinWithAND(DO_Rendah_pH_Rendah60, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah60 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah60->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak60, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang60 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang60->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah60, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi60 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi60->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang60, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti60 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule60 = new FuzzyRule(60,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi60, Ganti60);
  fuzzy->addFuzzyRule(fuzzyRule60);

  // Rule 61
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah61 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah61->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak61 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak61->joinWithAND(DO_Rendah_pH_Rendah61, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah61 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah61->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak61, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam61 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam61->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah61, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah61 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah61->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam61, EC_Rendah);
  FuzzyRuleConsequent *Ganti61 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule61 = new FuzzyRule(61,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah61, Ganti61);
  fuzzy->addFuzzyRule(fuzzyRule61);

  // Rule 62
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah62 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah62->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak62 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak62->joinWithAND(DO_Rendah_pH_Rendah62, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah62 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah62->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak62, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam62 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam62->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah62, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal62 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal62->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam62, EC_Normal);
  FuzzyRuleConsequent *Ganti62 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule62 = new FuzzyRule(62,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal62, Ganti62);
  fuzzy->addFuzzyRule(fuzzyRule62);

  // Rule 63
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah63 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah63->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak63 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak63->joinWithAND(DO_Rendah_pH_Rendah63, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah63 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah63->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak63, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam63 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam63->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah63, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi63 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi63->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam63, EC_Tinggi);
  FuzzyRuleConsequent *Ganti63 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule63 = new FuzzyRule(63,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi63, Ganti63);
  fuzzy->addFuzzyRule(fuzzyRule63);

  // Rule 64
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah64 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah64->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak64 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak64->joinWithAND(DO_Rendah_pH_Rendah64, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal64 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal64->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak64, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal64 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal64->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal64, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah64 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah64->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal64, EC_Rendah); 
  FuzzyRuleConsequent *Ganti64 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule64 = new FuzzyRule(64,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah64, Ganti64);
  fuzzy->addFuzzyRule(fuzzyRule64);

  // Rule 65
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah65 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah65->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak65 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak65->joinWithAND(DO_Rendah_pH_Rendah65, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal65 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal65->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak65, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal65 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal65->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal65, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal65= new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal65->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal65, EC_Normal); 
  FuzzyRuleConsequent *Ganti65 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule65 = new FuzzyRule(65,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal65, Ganti65);
  fuzzy->addFuzzyRule(fuzzyRule65);

  // Rule 66
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah66 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah66->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak66 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak66->joinWithAND(DO_Rendah_pH_Rendah66, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal66 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal66->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak66, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal66 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal66->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal66, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi66= new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi66->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal66, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti66 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule66 = new FuzzyRule(66,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi66, Ganti66);
  fuzzy->addFuzzyRule(fuzzyRule66);

  // Rule 67
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah67 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah67->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak67 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak67->joinWithAND(DO_Rendah_pH_Rendah67, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal67 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal67->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak67, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang67 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang67->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal67, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah67 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah67->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang67, EC_Rendah);  
  FuzzyRuleConsequent *Ganti67 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule67 = new FuzzyRule(67,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah67, Ganti67);
  fuzzy->addFuzzyRule(fuzzyRule67);

  // Rule 68
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah68 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah68->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak68 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak68->joinWithAND(DO_Rendah_pH_Rendah68, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal68 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal68->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak68, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang68 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang68->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal68, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal68 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal68->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang68, EC_Normal);  
  FuzzyRuleConsequent *Ganti68 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule68 = new FuzzyRule(68,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal68, Ganti68);
  fuzzy->addFuzzyRule(fuzzyRule68);


  // Rule 69
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah69 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah69->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak69 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak69->joinWithAND(DO_Rendah_pH_Rendah69, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal69 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal69->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak69, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang69 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang69->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal69, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi69 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi69->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang69, EC_Tinggi);  
  FuzzyRuleConsequent *Ganti69 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule69 = new FuzzyRule(69,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi69, Ganti69);
  fuzzy->addFuzzyRule(fuzzyRule69);

  // Rule 70
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah70 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah70->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak70 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak70->joinWithAND(DO_Rendah_pH_Rendah70, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal70 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal70->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak70, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam70 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam70->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal70, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah70 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah70->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam70, EC_Rendah);
  FuzzyRuleConsequent *Ganti70 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule70 = new FuzzyRule(70,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah70, Ganti70);
  fuzzy->addFuzzyRule(fuzzyRule70);

  // Rule 71
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah71 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah71->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak71 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak71->joinWithAND(DO_Rendah_pH_Rendah71, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal71 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal71->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak71, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam71 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam71->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal71, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal71 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal71->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam71, EC_Normal);
  FuzzyRuleConsequent *Ganti71 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule71 = new FuzzyRule(71,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal71, Ganti71);
  fuzzy->addFuzzyRule(fuzzyRule71);

  // Rule 72
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah72 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah72->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak72 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak72->joinWithAND(DO_Rendah_pH_Rendah72, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal72 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal72->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak72, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam72 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam72->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal72, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi72 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi72->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam72, EC_Tinggi);
  FuzzyRuleConsequent *Ganti72 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule72 = new FuzzyRule(72,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi72, Ganti72);
  fuzzy->addFuzzyRule(fuzzyRule72);

  // Rule 73
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah73 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah73->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak73 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak73->joinWithAND(DO_Rendah_pH_Rendah73, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak73 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak73->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak73, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal73 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal73->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak73, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah73 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah73->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal73, EC_Rendah);
  FuzzyRuleConsequent *Ganti73 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule73 = new FuzzyRule(73,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah73, Ganti73);
  fuzzy->addFuzzyRule(fuzzyRule73);

  // Rule 74
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah74 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah74->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak74 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak74->joinWithAND(DO_Rendah_pH_Rendah74, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak74 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak74->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak74, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal74 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal74->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak74, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal74 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal74->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal74, EC_Normal);
  FuzzyRuleConsequent *Ganti74 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule74 = new FuzzyRule(74,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal74, Ganti74);
  fuzzy->addFuzzyRule(fuzzyRule74);

  // Rule 75
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah75 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah75->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak75 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak75->joinWithAND(DO_Rendah_pH_Rendah75, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak75 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak75->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak75, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal75 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal75->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak75, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi75 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi75->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal75, EC_Tinggi);
  FuzzyRuleConsequent *Ganti75 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule75 = new FuzzyRule(75,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi75, Ganti75);
  fuzzy->addFuzzyRule(fuzzyRule75);

  // Rule 76
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah76 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah76->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak76 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak76->joinWithAND(DO_Rendah_pH_Rendah76, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak76 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak76->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak76, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang76 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang76->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak76, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah76 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah76->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang76, EC_Rendah); 
  FuzzyRuleConsequent *Ganti76 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule76 = new FuzzyRule(76,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah76, Ganti76);
  fuzzy->addFuzzyRule(fuzzyRule76);

  // Rule 77
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah77 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah77->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak77 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak77->joinWithAND(DO_Rendah_pH_Rendah77, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak77 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak77->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak77, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang77 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang77->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak77, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal77 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal77->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang77, EC_Normal); 
  FuzzyRuleConsequent *Ganti77 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule77 = new FuzzyRule(77,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal77, Ganti77);
  fuzzy->addFuzzyRule(fuzzyRule77);

  // Rule 78
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah78 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah78->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak78 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak78->joinWithAND(DO_Rendah_pH_Rendah78, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak78 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak78->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak78, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang78 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang78->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak78, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi78 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi78->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang78, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti78 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule78 = new FuzzyRule(78,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi78, Ganti78);
  fuzzy->addFuzzyRule(fuzzyRule78);

  // Rule 79
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah79 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah79->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak79 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak79->joinWithAND(DO_Rendah_pH_Rendah79, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak79 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak79->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak79, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam79 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam79->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak79, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah79 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah79->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam79, EC_Rendah);
  FuzzyRuleConsequent *Ganti79 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule79 = new FuzzyRule(79,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah79, Ganti79);
  fuzzy->addFuzzyRule(fuzzyRule79);

  // Rule 80
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah80 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah80->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak80 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak80->joinWithAND(DO_Rendah_pH_Rendah80, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak80 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak80->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak80, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam80 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam80->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak80, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal80 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal80->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam80, EC_Normal);
  FuzzyRuleConsequent *Ganti80 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule80 = new FuzzyRule(80,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal80, Ganti80);
  fuzzy->addFuzzyRule(fuzzyRule80);

  // Rule 81
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah81 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah81->joinWithAND(DO_Rendah, pH_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak81 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak81->joinWithAND(DO_Rendah_pH_Rendah81, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak81 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak81->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak81, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam81 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam81->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak81, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi81 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi81->joinWithAND(DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam81, EC_Tinggi);
  FuzzyRuleConsequent *Ganti81 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule81 = new FuzzyRule(81,DO_Rendah_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi81, Ganti81);
  fuzzy->addFuzzyRule(fuzzyRule81);

  // Rule 82
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal82 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal82->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah82 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah82->joinWithAND(DO_Rendah_pH_Normal82, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah82 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah82->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah82, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal82 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal82->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah82, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah82 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah82->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal82, EC_Rendah);
  FuzzyRuleConsequent *Ganti82 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule82 = new FuzzyRule(82,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah82, Ganti82);
  fuzzy->addFuzzyRule(fuzzyRule82);

  // Rule 83
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal83 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal83->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah83 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah83->joinWithAND(DO_Rendah_pH_Normal83, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah83 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah83->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah83, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal83 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal83->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah83, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal83 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal83->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal83, EC_Normal);
  FuzzyRuleConsequent *Ganti83 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule83 = new FuzzyRule(83,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal83, Ganti83);
  fuzzy->addFuzzyRule(fuzzyRule83);

  // Rule 84
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal84 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal84->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah84 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah84->joinWithAND(DO_Rendah_pH_Normal84, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah84 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah84->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah84, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal84 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal84->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah84, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi84 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi84->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal84, EC_Tinggi);
  FuzzyRuleConsequent *Ganti84 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule84 = new FuzzyRule(84,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi84, Ganti84);
  fuzzy->addFuzzyRule(fuzzyRule84);

  // Rule 85
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal85 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal85->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah85 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah85->joinWithAND(DO_Rendah_pH_Normal85, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah85 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah85->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah85, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang85 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang85->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah85, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah85 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah85->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang85, EC_Rendah);
  FuzzyRuleConsequent *Ganti85 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule85 = new FuzzyRule(85,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah85, Ganti85);
  fuzzy->addFuzzyRule(fuzzyRule85);

  // Rule 86
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal86 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal86->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah86 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah86->joinWithAND(DO_Rendah_pH_Normal86, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah86 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah86->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah86, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang86 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang86->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah86, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal86 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal86->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang86, EC_Normal);
  FuzzyRuleConsequent *Ganti86 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule86 = new FuzzyRule(86,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal86, Ganti86);
  fuzzy->addFuzzyRule(fuzzyRule86);

  // Rule 87
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal87 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal87->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah87 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah87->joinWithAND(DO_Rendah_pH_Normal87, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah87 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah87->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah87, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang87 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang87->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah87, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi87 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi87->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang87, EC_Tinggi);
  FuzzyRuleConsequent *Ganti87 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule87 = new FuzzyRule(87,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi87, Ganti87);
  fuzzy->addFuzzyRule(fuzzyRule87);

  // Rule 88
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal88 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal88->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah88 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah88->joinWithAND(DO_Rendah_pH_Normal88, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah88 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah88->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah88, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam88 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam88->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah88, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah88 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah88->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam88, EC_Rendah);
  FuzzyRuleConsequent *Ganti88 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule88 = new FuzzyRule(88,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah88, Ganti88);
  fuzzy->addFuzzyRule(fuzzyRule88);

  // Rule 89
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal89 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal89->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah89 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah89->joinWithAND(DO_Rendah_pH_Normal89, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah89 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah89->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah89, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam89 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam89->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah89, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal89 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal89->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam89, EC_Normal);
  FuzzyRuleConsequent *Ganti89 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule89 = new FuzzyRule(89,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal89, Ganti89);
  fuzzy->addFuzzyRule(fuzzyRule89);

  // Rule 90
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal90 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal90->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah90 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah90->joinWithAND(DO_Rendah_pH_Normal90, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah90 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah90->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah90, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam90 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam90->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah90, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi90 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi90->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam90, EC_Tinggi);
  FuzzyRuleConsequent *Ganti90 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule90 = new FuzzyRule(90,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi90, Ganti90);
  fuzzy->addFuzzyRule(fuzzyRule90);

  // Rule 91
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal91 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal91->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah91 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah91->joinWithAND(DO_Rendah_pH_Normal91, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal91 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal91->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah91, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal91 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal91->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal91, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah91 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah91->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal91, EC_Rendah);  
  FuzzyRuleConsequent *Ganti91 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule91 = new FuzzyRule(91,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah91, Ganti91);
  fuzzy->addFuzzyRule(fuzzyRule91);

  // Rule 92
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal92 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal92->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah92 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah92->joinWithAND(DO_Rendah_pH_Normal92, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal92 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal92->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah92, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal92 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal92->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal92, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal92 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal92->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal92, EC_Normal);  
  FuzzyRuleConsequent *Ganti92 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule92 = new FuzzyRule(92,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal92, Ganti92);
  fuzzy->addFuzzyRule(fuzzyRule92);

  // Rule 93
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal93 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal93->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah93 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah93->joinWithAND(DO_Rendah_pH_Normal93, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal93 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal93->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah93, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal93 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal93->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal93, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi93 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi93->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal93, EC_Tinggi);  
  FuzzyRuleConsequent *Ganti93 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule93 = new FuzzyRule(93,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi93, Ganti93);
  fuzzy->addFuzzyRule(fuzzyRule93);

  // Rule 94
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal94 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal94->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah94 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah94->joinWithAND(DO_Rendah_pH_Normal94, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal94 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal94->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah94, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang94 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang94->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal94, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah94 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah94->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang94, EC_Rendah); 
  FuzzyRuleConsequent *Ganti94 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule94 = new FuzzyRule(94,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah94, Ganti94);
  fuzzy->addFuzzyRule(fuzzyRule94);

  // Rule 95
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal95 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal95->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah95 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah95->joinWithAND(DO_Rendah_pH_Normal95, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal95 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal95->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah95, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang95 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang95->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal95, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal95 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal95 ->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang95, EC_Normal); 
  FuzzyRuleConsequent *Ganti95 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule95 = new FuzzyRule(95,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal95, Ganti95);
  fuzzy->addFuzzyRule(fuzzyRule95);

  // Rule 96
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal96 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal96->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah96 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah96->joinWithAND(DO_Rendah_pH_Normal96, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal96 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal96->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah96, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang96 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang96->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal96, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi96 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi96 ->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang96, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti96 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule96 = new FuzzyRule(96,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi96, Ganti96);
  fuzzy->addFuzzyRule(fuzzyRule96);

  // Rule 97
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal97 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal97->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah97 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah97->joinWithAND(DO_Rendah_pH_Normal97, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal97 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal97->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah97, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam97 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam97->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal97, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah97 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah97->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam97, EC_Rendah);
  FuzzyRuleConsequent *Ganti97 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule97 = new FuzzyRule(97,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah97, Ganti97);
  fuzzy->addFuzzyRule(fuzzyRule97);

  // Rule 98
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal98 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal98->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah98 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah98->joinWithAND(DO_Rendah_pH_Normal98, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal98 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal98->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah98, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam98 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam98->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal98, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal98 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal98->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam98, EC_Normal);
  FuzzyRuleConsequent *Ganti98 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule98 = new FuzzyRule(98,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal98, Ganti98);
  fuzzy->addFuzzyRule(fuzzyRule98);

  // Rule 99
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal99 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal99->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah99 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah99->joinWithAND(DO_Rendah_pH_Normal99, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal99 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal99->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah99, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam99 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam99->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal99, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi99 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi99->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam99, EC_Tinggi);
  FuzzyRuleConsequent *Ganti99 = new FuzzyRuleConsequent();
  Ganti1->addOutput(Ganti);
  FuzzyRule *fuzzyRule99 = new FuzzyRule(99,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi99, Ganti99);
  fuzzy->addFuzzyRule(fuzzyRule99);

}

bool FuzzyHandler::setinput(int index, float input)
{
  // Mengatur input untuk fuzzy dengan indeks yang ditentukan
  return fuzzy->setInput(index, input);
}

bool FuzzyHandler::fuzify()
{
  // Memulai proses fuzzifikasi
  return fuzzy->fuzzify();
}

int FuzzyHandler::output()
{
  // Mendapatkan nilai keluaran fuzzy
  return fuzzy->defuzzify(1);
}