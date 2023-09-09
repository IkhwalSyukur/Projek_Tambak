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
  Ganti2->addOutput(Ganti);
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
  Ganti3->addOutput(Ganti);
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
  Ganti4->addOutput(Ganti);
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
  Ganti5->addOutput(Ganti);
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
  Ganti6->addOutput(Ganti);
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
  Ganti7->addOutput(Ganti);
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
  Ganti8->addOutput(Ganti);
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
  Ganti9->addOutput(Ganti);
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
  Ganti10->addOutput(Ganti);
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
  Ganti11->addOutput(Ganti);
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
  Ganti12->addOutput(Ganti);
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
  Ganti13->addOutput(Ganti);
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
  Ganti14->addOutput(Ganti);
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
  Ganti15->addOutput(Ganti);
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
  Ganti16->addOutput(Ganti);
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
  Ganti17->addOutput(Ganti);
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
  Ganti18->addOutput(Ganti);
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
  Ganti19->addOutput(Ganti);
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
  Ganti20->addOutput(Ganti);
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
  Ganti21->addOutput(Ganti);
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
  Ganti22->addOutput(Ganti);
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
  Ganti23->addOutput(Ganti);
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
  Ganti24->addOutput(Ganti);
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
  Ganti25->addOutput(Ganti);
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
  Ganti26->addOutput(Ganti);
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
  Ganti27->addOutput(Ganti);
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
  Ganti28->addOutput(Ganti);
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
  Ganti29->addOutput(Ganti);
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
  Ganti30->addOutput(Ganti);
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
  Ganti31->addOutput(Ganti);
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
  Ganti32->addOutput(Ganti);
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
  Ganti33->addOutput(Ganti);
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
  Ganti34->addOutput(Ganti);
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
  Ganti35->addOutput(Ganti);
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
  Ganti36->addOutput(Ganti);
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
  Ganti37->addOutput(Ganti);
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
  Ganti38->addOutput(Ganti);
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
  Ganti39->addOutput(Ganti);
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
  Ganti40->addOutput(Ganti);
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
  Ganti41->addOutput(Ganti);
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
  Ganti42->addOutput(Ganti);
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
  Ganti43->addOutput(Ganti);
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
  Ganti44->addOutput(Ganti);
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
  Ganti45->addOutput(Ganti);
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
  Ganti46->addOutput(Ganti);
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
  Ganti47->addOutput(Ganti);
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
  Ganti48->addOutput(Ganti);
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
  Ganti49->addOutput(Ganti);
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
  Ganti50->addOutput(Ganti);
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
  Ganti51->addOutput(Ganti);
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
  Ganti52->addOutput(Ganti);
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
  Ganti53->addOutput(Ganti);
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
  Ganti54->addOutput(Ganti);
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
  Ganti55->addOutput(Ganti);
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
  Ganti56->addOutput(Ganti);
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
  Ganti57->addOutput(Ganti);
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
  Ganti58->addOutput(Ganti);
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
  Ganti59->addOutput(Ganti);
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
  Ganti60->addOutput(Ganti);
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
  Ganti61->addOutput(Ganti);
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
  Ganti62->addOutput(Ganti);
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
  Ganti63->addOutput(Ganti);
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
  Ganti64->addOutput(Ganti);
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
  Ganti65->addOutput(Ganti);
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
  Ganti66->addOutput(Ganti);
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
  Ganti67->addOutput(Ganti);
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
  Ganti68->addOutput(Ganti);
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
  Ganti69->addOutput(Ganti);
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
  Ganti70->addOutput(Ganti);
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
  Ganti71->addOutput(Ganti);
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
  Ganti72->addOutput(Ganti);
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
  Ganti73->addOutput(Ganti);
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
  Ganti74->addOutput(Ganti);
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
  Ganti75->addOutput(Ganti);
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
  Ganti76->addOutput(Ganti);
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
  Ganti77->addOutput(Ganti);
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
  Ganti78->addOutput(Ganti);
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
  Ganti79->addOutput(Ganti);
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
  Ganti80->addOutput(Ganti);
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
  Ganti81->addOutput(Ganti);
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
  Ganti82->addOutput(Ganti);
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
  Ganti83->addOutput(Ganti);
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
  Ganti84->addOutput(Ganti);
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
  Ganti85->addOutput(Ganti);
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
  Ganti86->addOutput(Ganti);
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
  Ganti87->addOutput(Ganti);
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
  Ganti88->addOutput(Ganti);
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
  Ganti89->addOutput(Ganti);
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
  Ganti90->addOutput(Ganti);
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
  Ganti91->addOutput(Ganti);
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
  Ganti92->addOutput(Ganti);
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
  Ganti93->addOutput(Ganti);
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
  Ganti94->addOutput(Ganti);
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
  Ganti95->addOutput(Ganti);
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
  Ganti96->addOutput(Ganti);
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
  Ganti97->addOutput(Ganti);
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
  Ganti98->addOutput(Ganti);
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
  Ganti99->addOutput(Ganti);
  FuzzyRule *fuzzyRule99 = new FuzzyRule(99,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi99, Ganti99);
  fuzzy->addFuzzyRule(fuzzyRule99);

  // Rule 100
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal100 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal100->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah100 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah100->joinWithAND(DO_Rendah_pH_Normal100, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak100 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak100->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah100, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal100 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal100->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak100, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah100 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah100->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal100, EC_Rendah);
  FuzzyRuleConsequent *Ganti100 = new FuzzyRuleConsequent();
  Ganti100->addOutput(Ganti);
  FuzzyRule *fuzzyRule100 = new FuzzyRule(100,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah100, Ganti100);
  fuzzy->addFuzzyRule(fuzzyRule100);

  // Rule 101
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal101 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal101->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah101 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah101->joinWithAND(DO_Rendah_pH_Normal101, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak101 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak101->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah101, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal101 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal101->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak101, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal101 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal101->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal101, EC_Normal);
  FuzzyRuleConsequent *Ganti101 = new FuzzyRuleConsequent();
  Ganti101->addOutput(Ganti);
  FuzzyRule *fuzzyRule101 = new FuzzyRule(101,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal101, Ganti101);
  fuzzy->addFuzzyRule(fuzzyRule101);

  // Rule 102
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal102 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal102->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah102 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah102->joinWithAND(DO_Rendah_pH_Normal102, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak102 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak102->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah102, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal102 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal102->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak102, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi102 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi102->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal102, EC_Tinggi);
  FuzzyRuleConsequent *Ganti102 = new FuzzyRuleConsequent();
  Ganti102->addOutput(Ganti);
  FuzzyRule *fuzzyRule102 = new FuzzyRule(102,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi102, Ganti102);
  fuzzy->addFuzzyRule(fuzzyRule102);

  // Rule 103
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal103 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal103->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah103 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah103->joinWithAND(DO_Rendah_pH_Normal103, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak103 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak103->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah103, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang103 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang103->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak103, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah103 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah103->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang103, EC_Rendah);
  FuzzyRuleConsequent *Ganti103 = new FuzzyRuleConsequent();
  Ganti103->addOutput(Ganti);
  FuzzyRule *fuzzyRule103 = new FuzzyRule(103,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah103, Ganti103);
  fuzzy->addFuzzyRule(fuzzyRule103);

  // Rule 104
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal104 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal104->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah104 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah104->joinWithAND(DO_Rendah_pH_Normal104, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak104 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak104->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah104, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang104 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang104->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak104, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal104 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal104->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang104, EC_Normal);
  FuzzyRuleConsequent *Ganti104 = new FuzzyRuleConsequent();
  Ganti104->addOutput(Ganti);
  FuzzyRule *fuzzyRule104 = new FuzzyRule(104,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal104, Ganti104);
  fuzzy->addFuzzyRule(fuzzyRule104);

  // Rule 105
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal105 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal105->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah105 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah105->joinWithAND(DO_Rendah_pH_Normal105, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak105 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak105->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah105, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang105 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang105->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak105, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi105 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi105->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang105, EC_Tinggi);
  FuzzyRuleConsequent *Ganti105 = new FuzzyRuleConsequent();
  Ganti105->addOutput(Ganti);
  FuzzyRule *fuzzyRule105 = new FuzzyRule(105,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi105, Ganti105);
  fuzzy->addFuzzyRule(fuzzyRule105);

  // Rule 106
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal106 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal106->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah106 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah106->joinWithAND(DO_Rendah_pH_Normal106, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak106 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak106->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah106, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam106 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam106->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak106, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah106 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah106->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam106, EC_Rendah);
  FuzzyRuleConsequent *Ganti106 = new FuzzyRuleConsequent();
  Ganti106->addOutput(Ganti);
  FuzzyRule *fuzzyRule106 = new FuzzyRule(106,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah106, Ganti106);
  fuzzy->addFuzzyRule(fuzzyRule106);

  // Rule 107
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal107 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal107->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah107 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah107->joinWithAND(DO_Rendah_pH_Normal107, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak107 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak107->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah107, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam107 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam107->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak107, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal107 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal107->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam107, EC_Normal);
  FuzzyRuleConsequent *Ganti107 = new FuzzyRuleConsequent();
  Ganti107->addOutput(Ganti);
  FuzzyRule *fuzzyRule107 = new FuzzyRule(107,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal107, Ganti107);
  fuzzy->addFuzzyRule(fuzzyRule107);

  // Rule 108
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal108 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal108->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah108 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah108->joinWithAND(DO_Rendah_pH_Normal108, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak108 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak108->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah108, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam108 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam108->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak108, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi108 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi108->joinWithAND(DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam108, EC_Tinggi);
  FuzzyRuleConsequent *Ganti108 = new FuzzyRuleConsequent();
  Ganti108->addOutput(Ganti);
  FuzzyRule *fuzzyRule108 = new FuzzyRule(108,DO_Rendah_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi108, Ganti108);
  fuzzy->addFuzzyRule(fuzzyRule108);

  // Rule 109
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal109 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal109->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal109 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal109->joinWithAND(DO_Rendah_pH_Normal109, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah109 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah109->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal109, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal109 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal109->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah109, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah109 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah109->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal109, EC_Rendah); 
  FuzzyRuleConsequent *Ganti109 = new FuzzyRuleConsequent();
  Ganti109->addOutput(Ganti);
  FuzzyRule *fuzzyRule109 = new FuzzyRule(109,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah109, Ganti109);
  fuzzy->addFuzzyRule(fuzzyRule109);

  // Rule 110
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal110 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal110->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal110 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal110->joinWithAND(DO_Rendah_pH_Normal110, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah110 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah110->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal110, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal110 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal110->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah110, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal110 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal110->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal110, EC_Normal); 
  FuzzyRuleConsequent *Ganti110 = new FuzzyRuleConsequent();
  Ganti110->addOutput(Ganti);
  FuzzyRule *fuzzyRule110 = new FuzzyRule(110,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal110, Ganti110);
  fuzzy->addFuzzyRule(fuzzyRule110);

  // Rule 111
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal111 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal111->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal111 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal111->joinWithAND(DO_Rendah_pH_Normal111, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah111 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah111->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal111, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal111 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal111->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah111, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi111 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi111->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal111, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti111 = new FuzzyRuleConsequent();
  Ganti111->addOutput(Ganti);
  FuzzyRule *fuzzyRule111 = new FuzzyRule(111,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi111, Ganti111);
  fuzzy->addFuzzyRule(fuzzyRule111);

  // Rule 112
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal112 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal112->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal112 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal112->joinWithAND(DO_Rendah_pH_Normal112, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah112 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah112->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal112, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang112 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang112->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah112, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah112 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah112->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang112, EC_Rendah);
  FuzzyRuleConsequent *Ganti112 = new FuzzyRuleConsequent();
  Ganti112->addOutput(Ganti);
  FuzzyRule *fuzzyRule112 = new FuzzyRule(112,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah112, Ganti112);
  fuzzy->addFuzzyRule(fuzzyRule112);

  // Rule 113
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal113 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal113->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal113 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal113->joinWithAND(DO_Rendah_pH_Normal113, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah113 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah113->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal113, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang113 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang113->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah113, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal113 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal113->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang113, EC_Normal);
  FuzzyRuleConsequent *Ganti113 = new FuzzyRuleConsequent();
  Ganti113->addOutput(Ganti);
  FuzzyRule *fuzzyRule113 = new FuzzyRule(113,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal113, Ganti113);
  fuzzy->addFuzzyRule(fuzzyRule113);

  // Rule 114
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal114 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal114->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal114 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal114->joinWithAND(DO_Rendah_pH_Normal114, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah114 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah114->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal114, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang114 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang114->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah114, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi114 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi114->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang114, EC_Tinggi);
  FuzzyRuleConsequent *Ganti114 = new FuzzyRuleConsequent();
  Ganti114->addOutput(Ganti);
  FuzzyRule *fuzzyRule114 = new FuzzyRule(114,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi114, Ganti114);
  fuzzy->addFuzzyRule(fuzzyRule114);

  // Rule 115
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal115 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal115->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal115 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal115->joinWithAND(DO_Rendah_pH_Normal115, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah115 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah115->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal115, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam115 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam115->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah115, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah115 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah115->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam115, EC_Rendah);
  FuzzyRuleConsequent *Ganti115 = new FuzzyRuleConsequent();
  Ganti115->addOutput(Ganti);
  FuzzyRule *fuzzyRule115 = new FuzzyRule(115,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah115, Ganti115);
  fuzzy->addFuzzyRule(fuzzyRule115);

  // Rule 116
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal116 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal116->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal116 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal116->joinWithAND(DO_Rendah_pH_Normal116, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah116 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah116->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal116, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam116 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam116->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah116, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal116 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal116->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam116, EC_Normal);
  FuzzyRuleConsequent *Ganti116 = new FuzzyRuleConsequent();
  Ganti116->addOutput(Ganti);
  FuzzyRule *fuzzyRule116 = new FuzzyRule(116,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal116, Ganti116);
  fuzzy->addFuzzyRule(fuzzyRule116);

  // Rule 117
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal117 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal117->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal117 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal117->joinWithAND(DO_Rendah_pH_Normal117, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah117 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah117->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal117, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam117 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam117->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah117, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi117 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi117->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam117, EC_Tinggi);
  FuzzyRuleConsequent *Ganti117 = new FuzzyRuleConsequent();
  Ganti117->addOutput(Ganti);
  FuzzyRule *fuzzyRule117 = new FuzzyRule(117,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi117, Ganti117);
  fuzzy->addFuzzyRule(fuzzyRule117);

  // Rule 118
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal118 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal118->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal118 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal118->joinWithAND(DO_Rendah_pH_Normal118, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal118 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal118->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal118, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal118 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal118->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal118, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah118 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah118->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal118, EC_Rendah);
  FuzzyRuleConsequent *Ganti118 = new FuzzyRuleConsequent();
  Ganti118->addOutput(Ganti);
  FuzzyRule *fuzzyRule118 = new FuzzyRule(118,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah118, Ganti118);
  fuzzy->addFuzzyRule(fuzzyRule118);

  // Rule 119
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal119 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal119->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal119 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal119->joinWithAND(DO_Rendah_pH_Normal119, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal119 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal119->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal119, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal119 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal119->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal119, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal119 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal119->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal119, EC_Normal);
  FuzzyRuleConsequent *Ganti119 = new FuzzyRuleConsequent();
  Ganti119->addOutput(Ganti);
  FuzzyRule *fuzzyRule119 = new FuzzyRule(119,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal119, Ganti119);
  fuzzy->addFuzzyRule(fuzzyRule119);

  // Rule 120
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal120 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal120->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal120 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal120->joinWithAND(DO_Rendah_pH_Normal120, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal120 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal120->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal120, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal120 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal120->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal120, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi120 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi120->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal120, EC_Tinggi);
  FuzzyRuleConsequent *Ganti120 = new FuzzyRuleConsequent();
  Ganti120->addOutput(Ganti);
  FuzzyRule *fuzzyRule120 = new FuzzyRule(120,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi120, Ganti120);
  fuzzy->addFuzzyRule(fuzzyRule120);

  // Rule 121
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal121 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal121->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal121 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal121->joinWithAND(DO_Rendah_pH_Normal121, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal121 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal121->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal121, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang121 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang121->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal121, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah121 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah121->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang121, EC_Rendah);
  FuzzyRuleConsequent *Ganti121 = new FuzzyRuleConsequent();
  Ganti121->addOutput(Ganti);
  FuzzyRule *fuzzyRule121 = new FuzzyRule(121,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah121, Ganti121);
  fuzzy->addFuzzyRule(fuzzyRule121);

  // Rule 122
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal122 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal122->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal122 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal122->joinWithAND(DO_Rendah_pH_Normal122, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal122 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal122->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal122, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang122 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang122->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal122, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal122 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal122->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang122, EC_Normal);
  FuzzyRuleConsequent *Ganti122 = new FuzzyRuleConsequent();
  Ganti122->addOutput(Ganti);
  FuzzyRule *fuzzyRule122 = new FuzzyRule(122,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal122, Ganti122);
  fuzzy->addFuzzyRule(fuzzyRule122);

  // Rule 123
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal123 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal123->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal123 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal123->joinWithAND(DO_Rendah_pH_Normal123, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal123 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal123->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal123, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang123 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang123->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal123, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi123 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi123->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang123, EC_Tinggi);
  FuzzyRuleConsequent *Ganti123 = new FuzzyRuleConsequent();
  Ganti123->addOutput(Ganti);
  FuzzyRule *fuzzyRule123 = new FuzzyRule(123,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi123, Ganti123);
  fuzzy->addFuzzyRule(fuzzyRule123);

  // Rule 124
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal124 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal124->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal124 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal124->joinWithAND(DO_Rendah_pH_Normal124, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal124 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal124->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal124, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam124 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam124->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal124, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah124 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah124->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam124, EC_Rendah);
  FuzzyRuleConsequent *Ganti124 = new FuzzyRuleConsequent();
  Ganti124->addOutput(Ganti);
  FuzzyRule *fuzzyRule124 = new FuzzyRule(124,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah124, Ganti124);
  fuzzy->addFuzzyRule(fuzzyRule124);

  // Rule 125
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal125 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal125->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal125 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal125->joinWithAND(DO_Rendah_pH_Normal125, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal125 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal125->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal125, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam125 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam125->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal125, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal125 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal125->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam125, EC_Normal);
  FuzzyRuleConsequent *Ganti125 = new FuzzyRuleConsequent();
  Ganti125->addOutput(Ganti);
  FuzzyRule *fuzzyRule125 = new FuzzyRule(125,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal125, Ganti125);
  fuzzy->addFuzzyRule(fuzzyRule125);

  // Rule 126
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal126 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal126->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal126 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal126->joinWithAND(DO_Rendah_pH_Normal126, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal126 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal126->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal126, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam126 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam126->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal126, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi126 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi126->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam126, EC_Tinggi);
  FuzzyRuleConsequent *Ganti126 = new FuzzyRuleConsequent();
  Ganti126->addOutput(Ganti);
  FuzzyRule *fuzzyRule126 = new FuzzyRule(126,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi126, Ganti126);
  fuzzy->addFuzzyRule(fuzzyRule126);

  // Rule 127
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal127 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal127->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal127 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal127->joinWithAND(DO_Rendah_pH_Normal127, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak127 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak127->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal127, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal127 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal127->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak127, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah127 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah127->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal127, EC_Rendah);  
  FuzzyRuleConsequent *Ganti127 = new FuzzyRuleConsequent();
  Ganti127->addOutput(Ganti);
  FuzzyRule *fuzzyRule127 = new FuzzyRule(127,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah127, Ganti127);
  fuzzy->addFuzzyRule(fuzzyRule127);

  // Rule 128
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal128 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal128->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal128 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal128->joinWithAND(DO_Rendah_pH_Normal128, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak128 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak128->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal128, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal128 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal128->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak128, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal128 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal128->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal128, EC_Normal);  
  FuzzyRuleConsequent *Ganti128 = new FuzzyRuleConsequent();
  Ganti128->addOutput(Ganti);
  FuzzyRule *fuzzyRule128 = new FuzzyRule(128,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal128, Ganti128);
  fuzzy->addFuzzyRule(fuzzyRule128);

  // Rule 129
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal129 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal129->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal129 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal129->joinWithAND(DO_Rendah_pH_Normal129, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak129 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak129->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal129, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal129 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal129->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak129, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi129 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi129->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal129, EC_Tinggi);  
  FuzzyRuleConsequent *Ganti129 = new FuzzyRuleConsequent();
  Ganti129->addOutput(Ganti);
  FuzzyRule *fuzzyRule129 = new FuzzyRule(129,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi129, Ganti129);
  fuzzy->addFuzzyRule(fuzzyRule129);

  // Rule 130
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal130 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal130->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal130 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal130->joinWithAND(DO_Rendah_pH_Normal130, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak130 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak130->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal130, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang130 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang130->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak130, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah130 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah130->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang130, EC_Rendah);  
  FuzzyRuleConsequent *Ganti130 = new FuzzyRuleConsequent();
  Ganti130->addOutput(Ganti);
  FuzzyRule *fuzzyRule130 = new FuzzyRule(130,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah130, Ganti130);
  fuzzy->addFuzzyRule(fuzzyRule130);

  // Rule 131
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal131 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal131->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal131 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal131->joinWithAND(DO_Rendah_pH_Normal131, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak131 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak131->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal131, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang131 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang131->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak131, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal131 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal131->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang131, EC_Normal);  
  FuzzyRuleConsequent *Ganti131 = new FuzzyRuleConsequent();
  Ganti131->addOutput(Ganti);
  FuzzyRule *fuzzyRule131 = new FuzzyRule(131,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal131, Ganti131);
  fuzzy->addFuzzyRule(fuzzyRule131);

  // Rule 132
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal132 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal132->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal132 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal132->joinWithAND(DO_Rendah_pH_Normal132, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak132 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak132->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal132, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang132 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang132->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak132, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi132 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi132->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang132, EC_Tinggi);  
  FuzzyRuleConsequent *Ganti132 = new FuzzyRuleConsequent();
  Ganti132->addOutput(Ganti);
  FuzzyRule *fuzzyRule132 = new FuzzyRule(132,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi132, Ganti132);
  fuzzy->addFuzzyRule(fuzzyRule132);

  // Rule 133
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal133 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal133->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal133 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal133->joinWithAND(DO_Rendah_pH_Normal133, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak133 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak133->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal133, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam133 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam133->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak133, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah133 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah133->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam133, EC_Rendah);
  FuzzyRuleConsequent *Ganti133 = new FuzzyRuleConsequent();
  Ganti133->addOutput(Ganti);
  FuzzyRule *fuzzyRule133 = new FuzzyRule(133,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah133, Ganti133);
  fuzzy->addFuzzyRule(fuzzyRule133);

  // Rule 134
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal134 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal134->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal134 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal134->joinWithAND(DO_Rendah_pH_Normal134, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak134 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak134->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal134, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam134 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam134->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak134, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal134 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal134->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam134, EC_Normal);
  FuzzyRuleConsequent *Ganti134 = new FuzzyRuleConsequent();
  Ganti134->addOutput(Ganti);
  FuzzyRule *fuzzyRule134 = new FuzzyRule(134,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal134, Ganti134);
  fuzzy->addFuzzyRule(fuzzyRule134);

  // Rule 135
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal135 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal135->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal135 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal135->joinWithAND(DO_Rendah_pH_Normal135, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak135 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak135->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal135, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam135 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam135->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak135, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi135 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi135->joinWithAND(DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam135, EC_Tinggi);
  FuzzyRuleConsequent *Ganti135 = new FuzzyRuleConsequent();
  Ganti135->addOutput(Ganti);
  FuzzyRule *fuzzyRule135 = new FuzzyRule(135,DO_Rendah_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi135, Ganti135);
  fuzzy->addFuzzyRule(fuzzyRule135);


  // Rule 136
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal136 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal136->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak136 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak136->joinWithAND(DO_Rendah_pH_Normal136, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah136 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah136->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak136, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal136 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal136->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah136, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah136 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah136->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal136, EC_Rendah);  
  FuzzyRuleConsequent *Ganti136 = new FuzzyRuleConsequent();
  Ganti136->addOutput(Ganti);
  FuzzyRule *fuzzyRule136 = new FuzzyRule(136,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah136, Ganti136);
  fuzzy->addFuzzyRule(fuzzyRule136);

  // Rule 137
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal137 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal137->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak137 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak137->joinWithAND(DO_Rendah_pH_Normal137, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah137 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah137->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak137, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal137 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal137->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah137, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal137 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal137->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal137, EC_Normal);  
  FuzzyRuleConsequent *Ganti137 = new FuzzyRuleConsequent();
  Ganti137->addOutput(Ganti);
  FuzzyRule *fuzzyRule137 = new FuzzyRule(137,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal137, Ganti137);
  fuzzy->addFuzzyRule(fuzzyRule137);

  // Rule 138
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal138 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal138->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak138 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak138->joinWithAND(DO_Rendah_pH_Normal138, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah138 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah138->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak138, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal138 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal138->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah138, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi138 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi138->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal138, EC_Tinggi);  
  FuzzyRuleConsequent *Ganti138 = new FuzzyRuleConsequent();
  Ganti138->addOutput(Ganti);
  FuzzyRule *fuzzyRule138 = new FuzzyRule(138,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi138, Ganti138);
  fuzzy->addFuzzyRule(fuzzyRule138);

  // Rule 139
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal139 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal139->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak139 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak139->joinWithAND(DO_Rendah_pH_Normal139, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah139 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah139->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak139, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang139 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang139->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah139, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah139 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah139->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang139, EC_Rendah);
  FuzzyRuleConsequent *Ganti139 = new FuzzyRuleConsequent();
  Ganti139->addOutput(Ganti);
  FuzzyRule *fuzzyRule139 = new FuzzyRule(139,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah139, Ganti139);
  fuzzy->addFuzzyRule(fuzzyRule139);

  // Rule 140
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal140 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal140->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak140 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak140->joinWithAND(DO_Rendah_pH_Normal140, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah140 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah140->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak140, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang140 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang140->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah140, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal140 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal140->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang140, EC_Normal);
  FuzzyRuleConsequent *Ganti140 = new FuzzyRuleConsequent();
  Ganti140->addOutput(Ganti);
  FuzzyRule *fuzzyRule140 = new FuzzyRule(140,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal140, Ganti140);
  fuzzy->addFuzzyRule(fuzzyRule140);

  // Rule 141
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal141 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal141->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak141 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak141->joinWithAND(DO_Rendah_pH_Normal141, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah141 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah141->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak141, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang141 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang141->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah141, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi141 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi141->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang141, EC_Tinggi);
  FuzzyRuleConsequent *Ganti141 = new FuzzyRuleConsequent();
  Ganti141->addOutput(Ganti);
  FuzzyRule *fuzzyRule141 = new FuzzyRule(141,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi141, Ganti141);
  fuzzy->addFuzzyRule(fuzzyRule141);

  // Rule 142
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal142 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal142->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak142 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak142->joinWithAND(DO_Rendah_pH_Normal142, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah142 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah142->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak142, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam142 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam142->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah142, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah142 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah142->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam142, EC_Rendah);
  FuzzyRuleConsequent *Ganti142 = new FuzzyRuleConsequent();
  Ganti142->addOutput(Ganti);
  FuzzyRule *fuzzyRule142 = new FuzzyRule(142,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah142, Ganti142);
  fuzzy->addFuzzyRule(fuzzyRule142);

  // Rule 143
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal143 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal143->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak143 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak143->joinWithAND(DO_Rendah_pH_Normal143, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah143 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah143->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak143, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam143 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam143->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah143, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal143 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal143->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam143, EC_Normal);
  FuzzyRuleConsequent *Ganti143 = new FuzzyRuleConsequent();
  Ganti143->addOutput(Ganti);
  FuzzyRule *fuzzyRule143 = new FuzzyRule(143,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal143, Ganti143);
  fuzzy->addFuzzyRule(fuzzyRule143);

  // Rule 144
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal144 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal144->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak144 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak144->joinWithAND(DO_Rendah_pH_Normal144, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah144 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah144->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak144, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam144 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam144->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah144, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi144 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi144->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam144, EC_Tinggi);
  FuzzyRuleConsequent *Ganti144 = new FuzzyRuleConsequent();
  Ganti144->addOutput(Ganti);
  FuzzyRule *fuzzyRule144 = new FuzzyRule(144,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi144, Ganti144);
  fuzzy->addFuzzyRule(fuzzyRule144);

  // Rule 145
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal145 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal145->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak145 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak145->joinWithAND(DO_Rendah_pH_Normal145, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal145 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal145->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak145, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal145 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal145->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal145, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah145 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah145->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal145, EC_Rendah);
  FuzzyRuleConsequent *Ganti145 = new FuzzyRuleConsequent();
  Ganti145->addOutput(Ganti);
  FuzzyRule *fuzzyRule145 = new FuzzyRule(145,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah145, Ganti145);
  fuzzy->addFuzzyRule(fuzzyRule145);

  // Rule 146
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal146 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal146->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak146 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak146->joinWithAND(DO_Rendah_pH_Normal146, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal146 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal146->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak146, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal146 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal146->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal146, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal146 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal146->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal146, EC_Normal);
  FuzzyRuleConsequent *Ganti146 = new FuzzyRuleConsequent();
  Ganti146->addOutput(Ganti);
  FuzzyRule *fuzzyRule146 = new FuzzyRule(146,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal146, Ganti146);
  fuzzy->addFuzzyRule(fuzzyRule146);

  // Rule 147
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal147 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal147->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak147 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak147->joinWithAND(DO_Rendah_pH_Normal147, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal147 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal147->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak147, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal147 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal147->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal147, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi147 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi147->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal147, EC_Tinggi);
  FuzzyRuleConsequent *Ganti147 = new FuzzyRuleConsequent();
  Ganti147->addOutput(Ganti);
  FuzzyRule *fuzzyRule147 = new FuzzyRule(147,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi147, Ganti147);
  fuzzy->addFuzzyRule(fuzzyRule147);

  // Rule 148
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal148 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal148->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak148 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak148->joinWithAND(DO_Rendah_pH_Normal148, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal148 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal148->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak148, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang148 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang148->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal148, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah148 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah148->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang148, EC_Rendah);
  FuzzyRuleConsequent *Ganti148 = new FuzzyRuleConsequent();
  Ganti148->addOutput(Ganti);
  FuzzyRule *fuzzyRule148 = new FuzzyRule(148,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah148, Ganti148);
  fuzzy->addFuzzyRule(fuzzyRule148);

  // Rule 149
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal149 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal149->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak149 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak149->joinWithAND(DO_Rendah_pH_Normal149, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal149 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal149->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak149, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang149 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang149->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal149, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal149 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal149->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang149, EC_Normal);
  FuzzyRuleConsequent *Ganti149 = new FuzzyRuleConsequent();
  Ganti149->addOutput(Ganti);
  FuzzyRule *fuzzyRule149 = new FuzzyRule(149,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal149, Ganti149);
  fuzzy->addFuzzyRule(fuzzyRule149);

  // Rule 150
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal150 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal150->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak150 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak150->joinWithAND(DO_Rendah_pH_Normal150, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal150 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal150->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak150, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang150 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang150->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal150, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi150 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi150->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang150, EC_Tinggi);
  FuzzyRuleConsequent *Ganti150 = new FuzzyRuleConsequent();
  Ganti150->addOutput(Ganti);
  FuzzyRule *fuzzyRule150 = new FuzzyRule(150,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi150, Ganti150);
  fuzzy->addFuzzyRule(fuzzyRule150);

  // Rule 151
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal151 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal151->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak151 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak151->joinWithAND(DO_Rendah_pH_Normal151, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal151 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal151->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak151, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam151 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam151->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal151, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah151 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah151->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam151, EC_Rendah);
  FuzzyRuleConsequent *Ganti151 = new FuzzyRuleConsequent();
  Ganti151->addOutput(Ganti);
  FuzzyRule *fuzzyRule151 = new FuzzyRule(151,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah151, Ganti151);
  fuzzy->addFuzzyRule(fuzzyRule151);

  // Rule 152
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal152 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal152->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak152 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak152->joinWithAND(DO_Rendah_pH_Normal152, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal152 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal152->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak152, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam152 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam152->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal152, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal152 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal152->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam152, EC_Normal);
  FuzzyRuleConsequent *Ganti152 = new FuzzyRuleConsequent();
  Ganti152->addOutput(Ganti);
  FuzzyRule *fuzzyRule152 = new FuzzyRule(152,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal152, Ganti152);
  fuzzy->addFuzzyRule(fuzzyRule152);

  // Rule 153
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal153 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal153->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak153 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak153->joinWithAND(DO_Rendah_pH_Normal153, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal153 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal153->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak153, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam153 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam153->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal153, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi153 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi153->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam153, EC_Tinggi);
  FuzzyRuleConsequent *Ganti153 = new FuzzyRuleConsequent();
  Ganti153->addOutput(Ganti);
  FuzzyRule *fuzzyRule153 = new FuzzyRule(153,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi153, Ganti153);
  fuzzy->addFuzzyRule(fuzzyRule153);

  // Rule 154
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal154 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal154->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak154 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak154->joinWithAND(DO_Rendah_pH_Normal154, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak154 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak154->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak154, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal154 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal154->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak154, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah154 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah154->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal154, EC_Rendah); 
  FuzzyRuleConsequent *Ganti154 = new FuzzyRuleConsequent();
  Ganti154->addOutput(Ganti);
  FuzzyRule *fuzzyRule154 = new FuzzyRule(154,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah154, Ganti154);
  fuzzy->addFuzzyRule(fuzzyRule154);

  // Rule 155
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal155 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal155->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak155 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak155->joinWithAND(DO_Rendah_pH_Normal155, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak155 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak155->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak155, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal155 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal155->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak155, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal155 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal155->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal155, EC_Normal); 
  FuzzyRuleConsequent *Ganti155 = new FuzzyRuleConsequent();
  Ganti155->addOutput(Ganti);
  FuzzyRule *fuzzyRule155 = new FuzzyRule(155,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal155, Ganti155);
  fuzzy->addFuzzyRule(fuzzyRule155);

  // Rule 156
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal156 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal156->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak156 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak156->joinWithAND(DO_Rendah_pH_Normal156, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak156 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak156->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak156, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal156 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal156->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak156, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi156 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi156->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal156, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti156 = new FuzzyRuleConsequent();
  Ganti156->addOutput(Ganti);
  FuzzyRule *fuzzyRule156 = new FuzzyRule(156,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi156, Ganti156);
  fuzzy->addFuzzyRule(fuzzyRule156);

  // Rule 157
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal157 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal157->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak157 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak157->joinWithAND(DO_Rendah_pH_Normal157, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak157 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak157->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak157, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang157 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang157->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak157, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah157 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah157->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang157, EC_Rendah);
  FuzzyRuleConsequent *Ganti157 = new FuzzyRuleConsequent();
  Ganti157->addOutput(Ganti);
  FuzzyRule *fuzzyRule157 = new FuzzyRule(157,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah157, Ganti157);
  fuzzy->addFuzzyRule(fuzzyRule157);

  // Rule 158
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal158 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal158->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak158 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak158->joinWithAND(DO_Rendah_pH_Normal158, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak158 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak158->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak158, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang158 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang158->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak158, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal158 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal158->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang158, EC_Normal);
  FuzzyRuleConsequent *Ganti158 = new FuzzyRuleConsequent();
  Ganti158->addOutput(Ganti);
  FuzzyRule *fuzzyRule158 = new FuzzyRule(158,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal158, Ganti158);
  fuzzy->addFuzzyRule(fuzzyRule158);

  // Rule 159
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal159 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal159->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak159 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak159->joinWithAND(DO_Rendah_pH_Normal159, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak159 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak159->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak159, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang159 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang159->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak159, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi159 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi159->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang159, EC_Tinggi);
  FuzzyRuleConsequent *Ganti159 = new FuzzyRuleConsequent();
  Ganti159->addOutput(Ganti);
  FuzzyRule *fuzzyRule159 = new FuzzyRule(159,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi159, Ganti159);
  fuzzy->addFuzzyRule(fuzzyRule159);

  // Rule 160
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal160 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal160->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak160 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak160->joinWithAND(DO_Rendah_pH_Normal160, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak160 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak160->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak160, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam160 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam160->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak160, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah160 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah160->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam160, EC_Rendah);
  FuzzyRuleConsequent *Ganti160 = new FuzzyRuleConsequent();
  Ganti160->addOutput(Ganti);
  FuzzyRule *fuzzyRule160 = new FuzzyRule(160,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah160, Ganti160);
  fuzzy->addFuzzyRule(fuzzyRule160);

  // Rule 161
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal161 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal161->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak161 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak161->joinWithAND(DO_Rendah_pH_Normal161, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak161 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak161->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak161, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam161 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam161->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak161, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal161 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal161->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam161, EC_Normal);
  FuzzyRuleConsequent *Ganti161 = new FuzzyRuleConsequent();
  Ganti161->addOutput(Ganti);
  FuzzyRule *fuzzyRule161 = new FuzzyRule(161,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal161, Ganti161);
  fuzzy->addFuzzyRule(fuzzyRule161);


  // Rule 162
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal162 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal162->joinWithAND(DO_Rendah, pH_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak162 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak162->joinWithAND(DO_Rendah_pH_Normal162, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak162 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak162->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak162, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam162 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam162->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak162, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi162 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi162->joinWithAND(DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam162, EC_Tinggi);
  FuzzyRuleConsequent *Ganti162 = new FuzzyRuleConsequent();
  Ganti162->addOutput(Ganti);
  FuzzyRule *fuzzyRule162 = new FuzzyRule(162,DO_Rendah_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi162, Ganti162);
  fuzzy->addFuzzyRule(fuzzyRule162);

  // Rule 163
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak163 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak163->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah163 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah163->joinWithAND(DO_Rendah_pH_Banyak163, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah163 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah163->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah163, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal163 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal163->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah163, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah163 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah163->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal163, EC_Rendah);
  FuzzyRuleConsequent *Ganti163 = new FuzzyRuleConsequent();
  Ganti163->addOutput(Ganti);
  FuzzyRule *fuzzyRule163 = new FuzzyRule(163,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah163, Ganti163);
  fuzzy->addFuzzyRule(fuzzyRule163);

  // Rule 164
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak164 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak164->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah164 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah164->joinWithAND(DO_Rendah_pH_Banyak164, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah164 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah164->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah164, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal164 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal164->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah164, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal164 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal164->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal164, EC_Normal);
  FuzzyRuleConsequent *Ganti164 = new FuzzyRuleConsequent();
  Ganti164->addOutput(Ganti);
  FuzzyRule *fuzzyRule164 = new FuzzyRule(164,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal164, Ganti164);
  fuzzy->addFuzzyRule(fuzzyRule164);

  // Rule 165
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak165 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak165->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah165 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah165->joinWithAND(DO_Rendah_pH_Banyak165, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah165 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah165->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah165, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal165 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal165->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah165, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi165 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi165->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal165, EC_Tinggi);
  FuzzyRuleConsequent *Ganti165 = new FuzzyRuleConsequent();
  Ganti165->addOutput(Ganti);
  FuzzyRule *fuzzyRule165 = new FuzzyRule(165,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi165, Ganti165);
  fuzzy->addFuzzyRule(fuzzyRule165);

  // Rule 166
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak166 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak166->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah166 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah166->joinWithAND(DO_Rendah_pH_Banyak166, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah166 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah166->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah166, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang166 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang166->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah166, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah166 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah166->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang166, EC_Rendah);
  FuzzyRuleConsequent *Ganti166 = new FuzzyRuleConsequent();
  Ganti166->addOutput(Ganti);
  FuzzyRule *fuzzyRule166 = new FuzzyRule(166,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah166, Ganti166);
  fuzzy->addFuzzyRule(fuzzyRule166);

  // Rule 167
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak167 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak167->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah167 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah167->joinWithAND(DO_Rendah_pH_Banyak167, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah167 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah167->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah167, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang167 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang167->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah167, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal167 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal167->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang167, EC_Normal);
  FuzzyRuleConsequent *Ganti167 = new FuzzyRuleConsequent();
  Ganti167->addOutput(Ganti);
  FuzzyRule *fuzzyRule167 = new FuzzyRule(167,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal167, Ganti167);
  fuzzy->addFuzzyRule(fuzzyRule167);

  // Rule 168
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak168 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak168->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah168 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah168->joinWithAND(DO_Rendah_pH_Banyak168, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah168 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah168->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah168, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang168 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang168->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah168, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi168 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi168->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang168, EC_Tinggi);
  FuzzyRuleConsequent *Ganti168 = new FuzzyRuleConsequent();
  Ganti168->addOutput(Ganti);
  FuzzyRule *fuzzyRule168 = new FuzzyRule(168,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi168, Ganti168);
  fuzzy->addFuzzyRule(fuzzyRule168);

  // Rule 169
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak169 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak169->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah169 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah169->joinWithAND(DO_Rendah_pH_Banyak169, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah169 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah169->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah169, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam169 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam169->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah169, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah169 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah169->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam169, EC_Rendah);
  FuzzyRuleConsequent *Ganti169 = new FuzzyRuleConsequent();
  Ganti169->addOutput(Ganti);
  FuzzyRule *fuzzyRule169 = new FuzzyRule(169,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah169, Ganti169);
  fuzzy->addFuzzyRule(fuzzyRule169);

  // Rule 170
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak170 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak170->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah170 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah170->joinWithAND(DO_Rendah_pH_Banyak170, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah170 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah170->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah170, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam170 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam170->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah170, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal170 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal170->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam170, EC_Normal);
  FuzzyRuleConsequent *Ganti170 = new FuzzyRuleConsequent();
  Ganti170->addOutput(Ganti);
  FuzzyRule *fuzzyRule170 = new FuzzyRule(170,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal170, Ganti170);
  fuzzy->addFuzzyRule(fuzzyRule170);

  // Rule 171
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak171 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak171->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah171 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah171->joinWithAND(DO_Rendah_pH_Banyak171, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah171 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah171->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah171, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam171 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam171->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah171, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi171 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi171->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam171, EC_Tinggi);
  FuzzyRuleConsequent *Ganti171 = new FuzzyRuleConsequent();
  Ganti171->addOutput(Ganti);
  FuzzyRule *fuzzyRule171 = new FuzzyRule(171,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi171, Ganti171);
  fuzzy->addFuzzyRule(fuzzyRule171);

  // Rule 172
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak172 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak172->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah172 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah172->joinWithAND(DO_Rendah_pH_Banyak172, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal172 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal172->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah172, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal172 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal172->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal172, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah172 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah172->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal172, EC_Rendah);
  FuzzyRuleConsequent *Ganti172 = new FuzzyRuleConsequent();
  Ganti172->addOutput(Ganti);
  FuzzyRule *fuzzyRule172 = new FuzzyRule(172,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah172, Ganti172);
  fuzzy->addFuzzyRule(fuzzyRule172);

  // Rule 173
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak173 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak173->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah173 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah173->joinWithAND(DO_Rendah_pH_Banyak173, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal173 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal173->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah173, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal173 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal173->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal173, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal173 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal173->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal173, EC_Normal);
  FuzzyRuleConsequent *Ganti173 = new FuzzyRuleConsequent();
  Ganti173->addOutput(Ganti);
  FuzzyRule *fuzzyRule173 = new FuzzyRule(173,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal173, Ganti173);
  fuzzy->addFuzzyRule(fuzzyRule173);

  // Rule 174
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak174 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak174->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah174 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah174->joinWithAND(DO_Rendah_pH_Banyak174, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal174 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal174->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah174, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal174 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal174->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal174, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi174 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi174->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal174, EC_Tinggi);
  FuzzyRuleConsequent *Ganti174 = new FuzzyRuleConsequent();
  Ganti174->addOutput(Ganti);
  FuzzyRule *fuzzyRule174 = new FuzzyRule(174,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi174, Ganti174);
  fuzzy->addFuzzyRule(fuzzyRule174);

  // Rule 175
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak175 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak175->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah175 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah175->joinWithAND(DO_Rendah_pH_Banyak175, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal175 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal175->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah175, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang175 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang175->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal175, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah175 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah175->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang175, EC_Rendah);
  FuzzyRuleConsequent *Ganti175 = new FuzzyRuleConsequent();
  Ganti175->addOutput(Ganti);
  FuzzyRule *fuzzyRule175 = new FuzzyRule(175,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah175, Ganti175);
  fuzzy->addFuzzyRule(fuzzyRule175);

  // Rule 176
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak176 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak176->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah176 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah176->joinWithAND(DO_Rendah_pH_Banyak176, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal176 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal176->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah176, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang176 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang176->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal176, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal176 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal176->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang176, EC_Normal);
  FuzzyRuleConsequent *Ganti176 = new FuzzyRuleConsequent();
  Ganti176->addOutput(Ganti);
  FuzzyRule *fuzzyRule176 = new FuzzyRule(176,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal176, Ganti176);
  fuzzy->addFuzzyRule(fuzzyRule176);

  // Rule 177
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak177 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak177->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah177 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah177->joinWithAND(DO_Rendah_pH_Banyak177, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal177 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal177->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah177, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang177 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang177->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal177, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi177 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi177->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang177, EC_Tinggi);
  FuzzyRuleConsequent *Ganti177 = new FuzzyRuleConsequent();
  Ganti177->addOutput(Ganti);
  FuzzyRule *fuzzyRule177 = new FuzzyRule(177,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi177, Ganti177);
  fuzzy->addFuzzyRule(fuzzyRule177);

  // Rule 178
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak178 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak178->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah178 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah178->joinWithAND(DO_Rendah_pH_Banyak178, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal178 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal178->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah178, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam178 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam178->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal178, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah178 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah178->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam178, EC_Rendah);
  FuzzyRuleConsequent *Ganti178 = new FuzzyRuleConsequent();
  Ganti178->addOutput(Ganti);
  FuzzyRule *fuzzyRule178 = new FuzzyRule(178,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah178, Ganti178);
  fuzzy->addFuzzyRule(fuzzyRule178);

  // Rule 179
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak179 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak179->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah179 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah179->joinWithAND(DO_Rendah_pH_Banyak179, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal179 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal179->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah179, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam179 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam179->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal179, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal179 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal179->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam179, EC_Normal);
  FuzzyRuleConsequent *Ganti179 = new FuzzyRuleConsequent();
  Ganti179->addOutput(Ganti);
  FuzzyRule *fuzzyRule179 = new FuzzyRule(179,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal179, Ganti179);
  fuzzy->addFuzzyRule(fuzzyRule179);

  // Rule 180
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak180 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak180->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah180 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah180->joinWithAND(DO_Rendah_pH_Banyak180, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal180 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal180->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah180, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam180 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam180->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal180, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi180 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi180->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam180, EC_Tinggi);
  FuzzyRuleConsequent *Ganti180 = new FuzzyRuleConsequent();
  Ganti180->addOutput(Ganti);
  FuzzyRule *fuzzyRule180 = new FuzzyRule(180,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi180, Ganti180);
  fuzzy->addFuzzyRule(fuzzyRule180);

  // Rule 181
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak181 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak181->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah181 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah181->joinWithAND(DO_Rendah_pH_Banyak181, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak181 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak181->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah181, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal181 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal181->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak181, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah181= new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah181->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal181, EC_Rendah);
  FuzzyRuleConsequent *Ganti181 = new FuzzyRuleConsequent();
  Ganti181->addOutput(Ganti);
  FuzzyRule *fuzzyRule181 = new FuzzyRule(181,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah181, Ganti181);
  fuzzy->addFuzzyRule(fuzzyRule181);

  // Rule 182
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak182 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak182->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah182 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah182->joinWithAND(DO_Rendah_pH_Banyak182, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak182 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak182->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah182, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal182 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal182->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak182, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal182 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal182->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal182, EC_Normal);
  FuzzyRuleConsequent *Ganti182 = new FuzzyRuleConsequent();
  Ganti182->addOutput(Ganti);
  FuzzyRule *fuzzyRule182 = new FuzzyRule(182,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal182, Ganti182);
  fuzzy->addFuzzyRule(fuzzyRule182);

  // Rule 183
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak183 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak183->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah183 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah183->joinWithAND(DO_Rendah_pH_Banyak183, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak183 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak183->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah183, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal183 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal183->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak183, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi183 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi183->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal183, EC_Tinggi);
  FuzzyRuleConsequent *Ganti183 = new FuzzyRuleConsequent();
  Ganti183->addOutput(Ganti);
  FuzzyRule *fuzzyRule183 = new FuzzyRule(183,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi183, Ganti183);
  fuzzy->addFuzzyRule(fuzzyRule183);

  // Rule 184
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak184 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak184->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah184 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah184->joinWithAND(DO_Rendah_pH_Banyak184, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak184 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak184->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah184, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang184 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang184->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak184, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah184 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah184->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang184, EC_Rendah); 
  FuzzyRuleConsequent *Ganti184 = new FuzzyRuleConsequent();
  Ganti184->addOutput(Ganti);
  FuzzyRule *fuzzyRule184 = new FuzzyRule(184,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah184, Ganti184);
  fuzzy->addFuzzyRule(fuzzyRule184);

  // Rule 185
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak185 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak185->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah185 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah185->joinWithAND(DO_Rendah_pH_Banyak185, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak185 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak185->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah185, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang185 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang185->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak185, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal185 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal185->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang185, EC_Normal); 
  FuzzyRuleConsequent *Ganti185 = new FuzzyRuleConsequent();
  Ganti185->addOutput(Ganti);
  FuzzyRule *fuzzyRule185 = new FuzzyRule(185,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal185, Ganti185);
  fuzzy->addFuzzyRule(fuzzyRule185);

  // Rule 186
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak186 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak186->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah186 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah186->joinWithAND(DO_Rendah_pH_Banyak186, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak186 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak186->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah186, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang186 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang186->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak186, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi186 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi186->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang186, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti186 = new FuzzyRuleConsequent();
  Ganti186->addOutput(Ganti);
  FuzzyRule *fuzzyRule186 = new FuzzyRule(186,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi186, Ganti186);
  fuzzy->addFuzzyRule(fuzzyRule186);

  // Rule 187
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak187 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak187->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah187 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah187->joinWithAND(DO_Rendah_pH_Banyak187, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak187 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak187->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah187, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam187 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam187->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak187, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah187 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah187->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam187, EC_Rendah); 
  FuzzyRuleConsequent *Ganti187 = new FuzzyRuleConsequent();
  Ganti187->addOutput(Ganti);
  FuzzyRule *fuzzyRule187 = new FuzzyRule(187,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah187, Ganti187);
  fuzzy->addFuzzyRule(fuzzyRule187);

  // Rule 188
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak188 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak188->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah188 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah188->joinWithAND(DO_Rendah_pH_Banyak188, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak188 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak188->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah188, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam188 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam188->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak188, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal188 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal188->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam188, EC_Normal); 
  FuzzyRuleConsequent *Ganti188 = new FuzzyRuleConsequent();
  Ganti188->addOutput(Ganti);
  FuzzyRule *fuzzyRule188 = new FuzzyRule(188,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal188, Ganti188);
  fuzzy->addFuzzyRule(fuzzyRule188);

  // Rule 189
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak189 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak189->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah189 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah189->joinWithAND(DO_Rendah_pH_Banyak189, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak189 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak189->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah189, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam189 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam189->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak189, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi189 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi189->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam189, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti189 = new FuzzyRuleConsequent();
  Ganti189->addOutput(Ganti);
  FuzzyRule *fuzzyRule189 = new FuzzyRule(189,DO_Rendah_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi189, Ganti189);
  fuzzy->addFuzzyRule(fuzzyRule189);

  // Rule 190
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak190 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak190->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal190 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal190->joinWithAND(DO_Rendah_pH_Banyak190, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah190 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah190->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal190, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal190 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal190->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah190, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah190 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah190->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal190, EC_Rendah);
  FuzzyRuleConsequent *Ganti190 = new FuzzyRuleConsequent();
  Ganti190->addOutput(Ganti);
  FuzzyRule *fuzzyRule190 = new FuzzyRule(190,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah190, Ganti190);
  fuzzy->addFuzzyRule(fuzzyRule190);

  // Rule 191
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak191 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak191->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal191 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal191->joinWithAND(DO_Rendah_pH_Banyak191, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah191 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah191->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal191, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal191 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal191->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah191, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal191 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal191->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal191, EC_Normal);
  FuzzyRuleConsequent *Ganti191 = new FuzzyRuleConsequent();
  Ganti191->addOutput(Ganti);
  FuzzyRule *fuzzyRule191 = new FuzzyRule(191,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal191, Ganti191);
  fuzzy->addFuzzyRule(fuzzyRule191);

  // Rule 192
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak192 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak192->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal192 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal192->joinWithAND(DO_Rendah_pH_Banyak192, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah192 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah192->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal192, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal192 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal192->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah192, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi192 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi192->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal192, EC_Tinggi);
  FuzzyRuleConsequent *Ganti192 = new FuzzyRuleConsequent();
  Ganti192->addOutput(Ganti);
  FuzzyRule *fuzzyRule192 = new FuzzyRule(192,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi192, Ganti192);
  fuzzy->addFuzzyRule(fuzzyRule192);

  // Rule 193
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak193 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak193->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal193 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal193->joinWithAND(DO_Rendah_pH_Banyak193, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah193 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah193->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal193, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang193 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang193->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah193, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah193 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah193->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang193, EC_Rendah);
  FuzzyRuleConsequent *Ganti193 = new FuzzyRuleConsequent();
  Ganti193->addOutput(Ganti);
  FuzzyRule *fuzzyRule193 = new FuzzyRule(193,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah193, Ganti193);
  fuzzy->addFuzzyRule(fuzzyRule193);

  // Rule 194
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak194 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak194->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal194 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal194->joinWithAND(DO_Rendah_pH_Banyak194, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah194 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah194->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal194, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang194 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang194->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah194, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal194 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal194->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang194, EC_Normal);
  FuzzyRuleConsequent *Ganti194 = new FuzzyRuleConsequent();
  Ganti194->addOutput(Ganti);
  FuzzyRule *fuzzyRule194 = new FuzzyRule(194,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal194, Ganti194);
  fuzzy->addFuzzyRule(fuzzyRule194);

  // Rule 195
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak195 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak195->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal195 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal195->joinWithAND(DO_Rendah_pH_Banyak195, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah195 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah195->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal195, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang195 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang195->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah195, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi195 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi195->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang195, EC_Tinggi);
  FuzzyRuleConsequent *Ganti195 = new FuzzyRuleConsequent();
  Ganti195->addOutput(Ganti);
  FuzzyRule *fuzzyRule195 = new FuzzyRule(195,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi195, Ganti195);
  fuzzy->addFuzzyRule(fuzzyRule195);

  // Rule 196
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak196 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak196->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal196 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal196->joinWithAND(DO_Rendah_pH_Banyak196, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah196 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah196->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal196, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam196 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam196->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah196, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah196 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah196->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam196, EC_Rendah);
  FuzzyRuleConsequent *Ganti196 = new FuzzyRuleConsequent();
  Ganti196->addOutput(Ganti);
  FuzzyRule *fuzzyRule196 = new FuzzyRule(196,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah196, Ganti196);
  fuzzy->addFuzzyRule(fuzzyRule196);

  // Rule 197
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak197 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak197->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal197 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal197->joinWithAND(DO_Rendah_pH_Banyak197, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah197 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah197->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal197, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam197 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam197->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah197, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal197 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal197->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam197, EC_Normal);
  FuzzyRuleConsequent *Ganti197 = new FuzzyRuleConsequent();
  Ganti197->addOutput(Ganti);
  FuzzyRule *fuzzyRule197 = new FuzzyRule(197,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal197, Ganti197);
  fuzzy->addFuzzyRule(fuzzyRule197);

  // Rule 198
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak198 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak198->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal198 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal198->joinWithAND(DO_Rendah_pH_Banyak198, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah198 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah198->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal198, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam198 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam198->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah198, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi198 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi198->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam198, EC_Tinggi);
  FuzzyRuleConsequent *Ganti198 = new FuzzyRuleConsequent();
  Ganti198->addOutput(Ganti);
  FuzzyRule *fuzzyRule198 = new FuzzyRule(198,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi198, Ganti198);
  fuzzy->addFuzzyRule(fuzzyRule198);

  // Rule 199
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak199 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak199->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal199 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal199->joinWithAND(DO_Rendah_pH_Banyak199, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal199 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal199->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal199, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal199 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal199->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal199, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah199 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah199->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal199, EC_Rendah); 
  FuzzyRuleConsequent *Ganti199 = new FuzzyRuleConsequent();
  Ganti199->addOutput(Ganti);
  FuzzyRule *fuzzyRule199 = new FuzzyRule(199,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah199, Ganti199);
  fuzzy->addFuzzyRule(fuzzyRule199);

  // Rule 200
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak200 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak200->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal200 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal200->joinWithAND(DO_Rendah_pH_Banyak200, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal200 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal200->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal200, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal200 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal200->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal200, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal200 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal200->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal200, EC_Normal); 
  FuzzyRuleConsequent *Ganti200 = new FuzzyRuleConsequent();
  Ganti200->addOutput(Ganti);
  FuzzyRule *fuzzyRule200 = new FuzzyRule(200,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal200, Ganti200);
  fuzzy->addFuzzyRule(fuzzyRule200);

  // Rule 201
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak201 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak201->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal201 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal201->joinWithAND(DO_Rendah_pH_Banyak201, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal201 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal201->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal201, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal201 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal201->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal201, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi201 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi201->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal201, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti201 = new FuzzyRuleConsequent();
  Ganti201->addOutput(Ganti);
  FuzzyRule *fuzzyRule201 = new FuzzyRule(201,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi201, Ganti201);
  fuzzy->addFuzzyRule(fuzzyRule201);

  // Rule 202
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak202 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak202->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal202 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal202->joinWithAND(DO_Rendah_pH_Banyak202, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal202 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal202->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal202, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang202 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang202->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal202, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah202 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah202->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang202, EC_Rendah); 
  FuzzyRuleConsequent *Ganti202 = new FuzzyRuleConsequent();
  Ganti202->addOutput(Ganti);
  FuzzyRule *fuzzyRule202 = new FuzzyRule(202,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah202, Ganti202);
  fuzzy->addFuzzyRule(fuzzyRule202);

  // Rule 203
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak203 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak203->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal203 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal203->joinWithAND(DO_Rendah_pH_Banyak203, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal203 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal203->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal203, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang203 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang203->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal203, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal203 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal203->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang203, EC_Normal); 
  FuzzyRuleConsequent *Ganti203 = new FuzzyRuleConsequent();
  Ganti203->addOutput(Ganti);
  FuzzyRule *fuzzyRule203 = new FuzzyRule(203,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal203, Ganti203);
  fuzzy->addFuzzyRule(fuzzyRule203);

  // Rule 204
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak204 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak204->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal204 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal204->joinWithAND(DO_Rendah_pH_Banyak204, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal204 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal204->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal204, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang204 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang204->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal204, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi204 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi204->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang204, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti204 = new FuzzyRuleConsequent();
  Ganti204->addOutput(Ganti);
  FuzzyRule *fuzzyRule204 = new FuzzyRule(204,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi204, Ganti204);
  fuzzy->addFuzzyRule(fuzzyRule204);

  // Rule 205
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak205 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak205->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal205 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal205->joinWithAND(DO_Rendah_pH_Banyak205, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal205 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal205->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal205, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam205 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam205->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal205, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah205 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah205->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam205, EC_Rendah);
  FuzzyRuleConsequent *Ganti205 = new FuzzyRuleConsequent();
  Ganti205->addOutput(Ganti);
  FuzzyRule *fuzzyRule205 = new FuzzyRule(205,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah205, Ganti205);
  fuzzy->addFuzzyRule(fuzzyRule205);

  // Rule 206
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak206 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak206->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal206 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal206->joinWithAND(DO_Rendah_pH_Banyak206, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal206 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal206->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal206, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam206 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam206->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal206, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal206 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal206->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam206, EC_Normal);
  FuzzyRuleConsequent *Ganti206 = new FuzzyRuleConsequent();
  Ganti206->addOutput(Ganti);
  FuzzyRule *fuzzyRule206 = new FuzzyRule(206,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal206, Ganti206);
  fuzzy->addFuzzyRule(fuzzyRule206);

  // Rule 207
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak207 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak207->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal207 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal207->joinWithAND(DO_Rendah_pH_Banyak207, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal207 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal207->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal207, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam207 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam207->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal207, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi207 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi207->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam207, EC_Tinggi);
  FuzzyRuleConsequent *Ganti207 = new FuzzyRuleConsequent();
  Ganti207->addOutput(Ganti);
  FuzzyRule *fuzzyRule207 = new FuzzyRule(207,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi207, Ganti207);
  fuzzy->addFuzzyRule(fuzzyRule207);

  // Rule 208
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak208 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak208->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal208 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal208->joinWithAND(DO_Rendah_pH_Banyak208, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak208 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak208->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal208, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal208 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal208->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak208, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah208 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah208->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal208, EC_Rendah);
  FuzzyRuleConsequent *Ganti208 = new FuzzyRuleConsequent();
  Ganti208->addOutput(Ganti);
  FuzzyRule *fuzzyRule208 = new FuzzyRule(208,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah208, Ganti208);
  fuzzy->addFuzzyRule(fuzzyRule208);

  // Rule 209
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak209 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak209->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal209 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal209->joinWithAND(DO_Rendah_pH_Banyak209, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak209 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak209->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal209, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal209 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal209->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak209, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal209 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal209->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal209, EC_Normal);
  FuzzyRuleConsequent *Ganti209 = new FuzzyRuleConsequent();
  Ganti209->addOutput(Ganti);
  FuzzyRule *fuzzyRule209 = new FuzzyRule(209,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal209, Ganti209);
  fuzzy->addFuzzyRule(fuzzyRule209);

  // Rule 210
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak210 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak210->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal210 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal210->joinWithAND(DO_Rendah_pH_Banyak210, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak210 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak210->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal210, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal210 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal210->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak210, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi210 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi210->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal210, EC_Tinggi);
  FuzzyRuleConsequent *Ganti210 = new FuzzyRuleConsequent();
  Ganti210->addOutput(Ganti);
  FuzzyRule *fuzzyRule210 = new FuzzyRule(210,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi210, Ganti210);
  fuzzy->addFuzzyRule(fuzzyRule210);

  // Rule 211
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak211 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak211->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal211 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal211->joinWithAND(DO_Rendah_pH_Banyak211, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak211 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak211->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal211, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang211 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang211->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak211, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah211 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah211->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang211, EC_Rendah);
  FuzzyRuleConsequent *Ganti211 = new FuzzyRuleConsequent();
  Ganti211->addOutput(Ganti);
  FuzzyRule *fuzzyRule211 = new FuzzyRule(211,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah211, Ganti211);
  fuzzy->addFuzzyRule(fuzzyRule211);

  // Rule 212
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak212 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak212->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal212 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal212->joinWithAND(DO_Rendah_pH_Banyak212, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak212 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak212->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal212, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang212 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang212->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak212, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal212 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal212->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang212, EC_Normal);
  FuzzyRuleConsequent *Ganti212 = new FuzzyRuleConsequent();
  Ganti212->addOutput(Ganti);
  FuzzyRule *fuzzyRule212 = new FuzzyRule(212,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal212, Ganti212);
  fuzzy->addFuzzyRule(fuzzyRule212);

  // Rule 213
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak213 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak213->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal213 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal213->joinWithAND(DO_Rendah_pH_Banyak213, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak213 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak213->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal213, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang213 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang213->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak213, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi213 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi213->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang213, EC_Tinggi);
  FuzzyRuleConsequent *Ganti213 = new FuzzyRuleConsequent();
  Ganti213->addOutput(Ganti);
  FuzzyRule *fuzzyRule213 = new FuzzyRule(213,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi213, Ganti213);
  fuzzy->addFuzzyRule(fuzzyRule213);

  // Rule 214
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak214 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak214->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal214 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal214->joinWithAND(DO_Rendah_pH_Banyak214, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak214 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak214->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal214, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam214 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam214->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak214, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah214 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah214->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam214, EC_Rendah);
  FuzzyRuleConsequent *Ganti214 = new FuzzyRuleConsequent();
  Ganti214->addOutput(Ganti);
  FuzzyRule *fuzzyRule214 = new FuzzyRule(214,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah214, Ganti214);
  fuzzy->addFuzzyRule(fuzzyRule214);

  // Rule 215
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak215 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak215->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal215 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal215->joinWithAND(DO_Rendah_pH_Banyak215, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak215 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak215->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal215, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam215 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam215->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak215, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal215 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal215->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam215, EC_Normal);
  FuzzyRuleConsequent *Ganti215 = new FuzzyRuleConsequent();
  Ganti215->addOutput(Ganti);
  FuzzyRule *fuzzyRule215 = new FuzzyRule(215,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal215, Ganti215);
  fuzzy->addFuzzyRule(fuzzyRule215);

  // Rule 216
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak216 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak216->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal216 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal216->joinWithAND(DO_Rendah_pH_Banyak216, Suhu_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak216 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak216->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal216, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam216 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam216->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak216, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi216 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi216->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam216, EC_Tinggi);
  FuzzyRuleConsequent *Ganti216 = new FuzzyRuleConsequent();
  Ganti216->addOutput(Ganti);
  FuzzyRule *fuzzyRule216 = new FuzzyRule(216,DO_Rendah_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi216, Ganti216);
  fuzzy->addFuzzyRule(fuzzyRule216);

  // Rule 217
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak217 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak217->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak217 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak217->joinWithAND(DO_Rendah_pH_Banyak217, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah217 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah217->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak217, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal217 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal217->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah217, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah217 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah217->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal217, EC_Rendah);
  FuzzyRuleConsequent *Ganti217 = new FuzzyRuleConsequent();
  Ganti217->addOutput(Ganti);
  FuzzyRule *fuzzyRule217 = new FuzzyRule(217,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah217, Ganti217);
  fuzzy->addFuzzyRule(fuzzyRule217);

  // Rule 218
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak218 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak218->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak218 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak218->joinWithAND(DO_Rendah_pH_Banyak218, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah218 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah218->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak218, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal218 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal218->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah218, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal218 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal218->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal218, EC_Normal);
  FuzzyRuleConsequent *Ganti218 = new FuzzyRuleConsequent();
  Ganti218->addOutput(Ganti);
  FuzzyRule *fuzzyRule218 = new FuzzyRule(218,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal218, Ganti218);
  fuzzy->addFuzzyRule(fuzzyRule218);

  // Rule 219
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak219 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak219->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak219 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak219->joinWithAND(DO_Rendah_pH_Banyak219, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah219 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah219->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak219, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal219 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal219->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah219, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi219 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi219->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal219, EC_Tinggi);
  FuzzyRuleConsequent *Ganti219 = new FuzzyRuleConsequent();
  Ganti219->addOutput(Ganti);
  FuzzyRule *fuzzyRule219 = new FuzzyRule(219,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi219, Ganti219);
  fuzzy->addFuzzyRule(fuzzyRule219);

  // Rule 220
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak220 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak220->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak220 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak220->joinWithAND(DO_Rendah_pH_Banyak220, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah220 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah220->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak220, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang220 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang220->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah220, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah220 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah220->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang220, EC_Rendah);
  FuzzyRuleConsequent *Ganti220 = new FuzzyRuleConsequent();
  Ganti220->addOutput(Ganti);
  FuzzyRule *fuzzyRule220 = new FuzzyRule(220,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah220, Ganti220);
  fuzzy->addFuzzyRule(fuzzyRule220);

  // Rule 221
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak221 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak221->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak221 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak221->joinWithAND(DO_Rendah_pH_Banyak221, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah221 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah221->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak221, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang221 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang221->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah221, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal221 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal221->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang221, EC_Normal);
  FuzzyRuleConsequent *Ganti221 = new FuzzyRuleConsequent();
  Ganti221->addOutput(Ganti);
  FuzzyRule *fuzzyRule221 = new FuzzyRule(221,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal221, Ganti221);
  fuzzy->addFuzzyRule(fuzzyRule221);

  // Rule 222
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak222 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak222->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak222 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak222->joinWithAND(DO_Rendah_pH_Banyak222, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah222 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah222->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak222, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang222 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang222->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah222, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi222 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi222->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang222, EC_Tinggi);
  FuzzyRuleConsequent *Ganti222 = new FuzzyRuleConsequent();
  Ganti222->addOutput(Ganti);
  FuzzyRule *fuzzyRule222 = new FuzzyRule(222,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi222, Ganti222);
  fuzzy->addFuzzyRule(fuzzyRule222);

  // Rule 223
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak223 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak223->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak223 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak223->joinWithAND(DO_Rendah_pH_Banyak223, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah223 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah223->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak223, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam223 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam223->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah223, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah223 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah223->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam223, EC_Rendah);
  FuzzyRuleConsequent *Ganti223 = new FuzzyRuleConsequent();
  Ganti223->addOutput(Ganti);
  FuzzyRule *fuzzyRule223 = new FuzzyRule(223,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah223, Ganti223);
  fuzzy->addFuzzyRule(fuzzyRule223);

  // Rule 224
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak224 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak224->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak224 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak224->joinWithAND(DO_Rendah_pH_Banyak224, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah224 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah224->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak224, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam224 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam224->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah224, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal224 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal224->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam224, EC_Normal);
  FuzzyRuleConsequent *Ganti224 = new FuzzyRuleConsequent();
  Ganti224->addOutput(Ganti);
  FuzzyRule *fuzzyRule224 = new FuzzyRule(224,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal224, Ganti224);
  fuzzy->addFuzzyRule(fuzzyRule224);

  // Rule 225
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak225 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak225->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak225 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak225->joinWithAND(DO_Rendah_pH_Banyak225, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah225 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah225->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak225, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam225 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam225->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah225, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi225 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi225->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam225, EC_Tinggi);
  FuzzyRuleConsequent *Ganti225 = new FuzzyRuleConsequent();
  Ganti225->addOutput(Ganti);
  FuzzyRule *fuzzyRule225 = new FuzzyRule(225,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi225, Ganti225);
  fuzzy->addFuzzyRule(fuzzyRule225);

  // Rule 226
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak226 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak226->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak226 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak226->joinWithAND(DO_Rendah_pH_Banyak226, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal226 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal226->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak226, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal226 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal226->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal226, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah226 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah226->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal226, EC_Rendah); 
  FuzzyRuleConsequent *Ganti226 = new FuzzyRuleConsequent();
  Ganti226->addOutput(Ganti);
  FuzzyRule *fuzzyRule226 = new FuzzyRule(226,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah226, Ganti226);
  fuzzy->addFuzzyRule(fuzzyRule226);

  // Rule 227
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak227 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak227->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak227 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak227->joinWithAND(DO_Rendah_pH_Banyak227, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal227 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal227->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak227, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal227 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal227->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal227, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal227 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal227->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal227, EC_Normal); 
  FuzzyRuleConsequent *Ganti227 = new FuzzyRuleConsequent();
  Ganti227->addOutput(Ganti);
  FuzzyRule *fuzzyRule227 = new FuzzyRule(227,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal227, Ganti227);
  fuzzy->addFuzzyRule(fuzzyRule227);

  // Rule 228
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak228 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak228->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak228 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak228->joinWithAND(DO_Rendah_pH_Banyak228, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal228 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal228->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak228, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal228 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal228->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal228, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi228 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi228->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal228, EC_Tinggi); 
  FuzzyRuleConsequent *Ganti228 = new FuzzyRuleConsequent();
  Ganti228->addOutput(Ganti);
  FuzzyRule *fuzzyRule228 = new FuzzyRule(228,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi228, Ganti228);
  fuzzy->addFuzzyRule(fuzzyRule228);

  // Rule 229
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak229 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak229->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak229 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak229->joinWithAND(DO_Rendah_pH_Banyak229, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal229 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal229->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak229, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang229 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang229->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal229, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah229 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah229->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang229, EC_Rendah);
  FuzzyRuleConsequent *Ganti229 = new FuzzyRuleConsequent();
  Ganti229->addOutput(Ganti);
  FuzzyRule *fuzzyRule229 = new FuzzyRule(229,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah229, Ganti229);
  fuzzy->addFuzzyRule(fuzzyRule229);

  // Rule 230
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak230 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak230->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak230 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak230->joinWithAND(DO_Rendah_pH_Banyak230, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal230 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal230->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak230, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang230 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang230->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal230, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal230 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal230->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang230, EC_Normal);
  FuzzyRuleConsequent *Ganti230 = new FuzzyRuleConsequent();
  Ganti230->addOutput(Ganti);
  FuzzyRule *fuzzyRule230 = new FuzzyRule(230,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal230, Ganti230);
  fuzzy->addFuzzyRule(fuzzyRule230);

  // Rule 231
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak231 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak231->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak231 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak231->joinWithAND(DO_Rendah_pH_Banyak231, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal231 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal231->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak231, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang231 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang231->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal231, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi231 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi231->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang231, EC_Tinggi);
  FuzzyRuleConsequent *Ganti231 = new FuzzyRuleConsequent();
  Ganti231->addOutput(Ganti);
  FuzzyRule *fuzzyRule231 = new FuzzyRule(231,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi231, Ganti231);
  fuzzy->addFuzzyRule(fuzzyRule231);

  // Rule 232
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak232 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak232->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak232 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak232->joinWithAND(DO_Rendah_pH_Banyak232, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal232 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal232->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak232, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam232 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam232->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal232, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah232 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah232->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam232, EC_Rendah);
  FuzzyRuleConsequent *Ganti232 = new FuzzyRuleConsequent();
  Ganti232->addOutput(Ganti);
  FuzzyRule *fuzzyRule232 = new FuzzyRule(232,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah232, Ganti232);
  fuzzy->addFuzzyRule(fuzzyRule232);

  // Rule 233
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak233 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak233->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak233 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak233->joinWithAND(DO_Rendah_pH_Banyak233, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal233 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal233->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak233, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam233 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam233->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal233, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal233 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal233->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam233, EC_Normal);
  FuzzyRuleConsequent *Ganti233 = new FuzzyRuleConsequent();
  Ganti233->addOutput(Ganti);
  FuzzyRule *fuzzyRule233 = new FuzzyRule(233,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal233, Ganti233);
  fuzzy->addFuzzyRule(fuzzyRule233);

  // Rule 234
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak234 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak234->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak234 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak234->joinWithAND(DO_Rendah_pH_Banyak234, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal234 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal234->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak234, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam234 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam234->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal234, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi234 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi234->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam234, EC_Tinggi);
  FuzzyRuleConsequent *Ganti234 = new FuzzyRuleConsequent();
  Ganti234->addOutput(Ganti);
  FuzzyRule *fuzzyRule234 = new FuzzyRule(234,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi234, Ganti234);
  fuzzy->addFuzzyRule(fuzzyRule234);

  // Rule 235
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak235 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak235->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak235 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak235->joinWithAND(DO_Rendah_pH_Banyak235, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak235 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak235->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak235, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal235 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal235->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak235, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah235 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah235->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal235, EC_Rendah);
  FuzzyRuleConsequent *Ganti235 = new FuzzyRuleConsequent();
  Ganti235->addOutput(Ganti);
  FuzzyRule *fuzzyRule235 = new FuzzyRule(235,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah235, Ganti235);
  fuzzy->addFuzzyRule(fuzzyRule235);

  // Rule 236
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak236 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak236->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak236 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak236->joinWithAND(DO_Rendah_pH_Banyak236, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak236 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak236->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak236, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal236 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal236->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak236, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal236 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal236->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal236, EC_Normal);
  FuzzyRuleConsequent *Ganti236 = new FuzzyRuleConsequent();
  Ganti236->addOutput(Ganti);
  FuzzyRule *fuzzyRule236 = new FuzzyRule(236,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal236, Ganti236);
  fuzzy->addFuzzyRule(fuzzyRule236);

  // Rule 237
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak237 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak237->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak237 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak237->joinWithAND(DO_Rendah_pH_Banyak237, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak237 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak237->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak237, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal237 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal237->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak237, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi237 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi237->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal237, EC_Tinggi);
  FuzzyRuleConsequent *Ganti237 = new FuzzyRuleConsequent();
  Ganti237->addOutput(Ganti);
  FuzzyRule *fuzzyRule237 = new FuzzyRule(237,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi237, Ganti237);
  fuzzy->addFuzzyRule(fuzzyRule237);

  // Rule 238
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak238 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak238->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak238 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak238->joinWithAND(DO_Rendah_pH_Banyak238, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak238 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak238->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak238, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang238 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang238->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak238, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah238 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah238->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang238, EC_Rendah);
  FuzzyRuleConsequent *Ganti238 = new FuzzyRuleConsequent();
  Ganti238->addOutput(Ganti);
  FuzzyRule *fuzzyRule238 = new FuzzyRule(238,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah238, Ganti238);
  fuzzy->addFuzzyRule(fuzzyRule238);

  // Rule 239
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak239 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak239->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak239 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak239->joinWithAND(DO_Rendah_pH_Banyak239, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak239 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak239->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak239, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang239 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang239->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak239, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal239 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal239->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang239, EC_Normal);
  FuzzyRuleConsequent *Ganti239 = new FuzzyRuleConsequent();
  Ganti239->addOutput(Ganti);
  FuzzyRule *fuzzyRule239 = new FuzzyRule(239,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal239, Ganti239);
  fuzzy->addFuzzyRule(fuzzyRule239);

  // Rule 240
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak240 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak240->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak240 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak240->joinWithAND(DO_Rendah_pH_Banyak240, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak240 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak240->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak240, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang240 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang240->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak240, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi240 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi240->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang240, EC_Tinggi);
  FuzzyRuleConsequent *Ganti240 = new FuzzyRuleConsequent();
  Ganti240->addOutput(Ganti);
  FuzzyRule *fuzzyRule240 = new FuzzyRule(240,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi240, Ganti240);
  fuzzy->addFuzzyRule(fuzzyRule240);


  // Rule 241
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak241 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak241->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak241 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak241->joinWithAND(DO_Rendah_pH_Banyak241, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak241 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak241->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak241, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam241 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam241->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak241, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah241 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah241->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam241, EC_Rendah);
  FuzzyRuleConsequent *Ganti241 = new FuzzyRuleConsequent();
  Ganti241->addOutput(Ganti);
  FuzzyRule *fuzzyRule241 = new FuzzyRule(241,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah241, Ganti241);
  fuzzy->addFuzzyRule(fuzzyRule241);

  // Rule 242
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak242 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak242->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak242 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak242->joinWithAND(DO_Rendah_pH_Banyak242, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak242 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak242->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak242, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam242 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam242->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak242, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal242 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal242->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam242, EC_Normal);
  FuzzyRuleConsequent *Ganti242 = new FuzzyRuleConsequent();
  Ganti242->addOutput(Ganti);
  FuzzyRule *fuzzyRule242 = new FuzzyRule(242,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal242, Ganti242);
  fuzzy->addFuzzyRule(fuzzyRule242);

  // Rule 243
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak243 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak243->joinWithAND(DO_Rendah, pH_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak243 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak243->joinWithAND(DO_Rendah_pH_Banyak243, Suhu_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak243 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak243->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak243, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam243 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam243->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak243, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi243 = new FuzzyRuleAntecedent();
  DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi243->joinWithAND(DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam243, EC_Tinggi);
  FuzzyRuleConsequent *Ganti243 = new FuzzyRuleConsequent();
  Ganti243->addOutput(Ganti);
  FuzzyRule *fuzzyRule243 = new FuzzyRule(243,DO_Rendah_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi243, Ganti243);
  fuzzy->addFuzzyRule(fuzzyRule243);

  //Rules 244
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah244 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah244->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah244 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah244->joinWithAND(DO_Normal_pH_Rendah244, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah244 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah244->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah244, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal244 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal244->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah244, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah244 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah244->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal244, EC_Rendah);
  FuzzyRuleConsequent *Ganti244 = new FuzzyRuleConsequent();
  Ganti244->addOutput(Ganti);
  FuzzyRule *fuzzyRule244 = new FuzzyRule(244,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah244, Ganti244);
  fuzzy->addFuzzyRule(fuzzyRule244);

  //Rules 245
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah245 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah245->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah245 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah245->joinWithAND(DO_Normal_pH_Rendah245, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah245 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah245->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah245, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal245 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal245->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah245, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal245 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal245->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal245, EC_Normal);
  FuzzyRuleConsequent *Ganti245 = new FuzzyRuleConsequent();
  Ganti245->addOutput(Ganti);
  FuzzyRule *fuzzyRule245 = new FuzzyRule(245,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal245, Ganti245);
  fuzzy->addFuzzyRule(fuzzyRule245);

  //Rules 246
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah246 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah246->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah246 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah246->joinWithAND(DO_Normal_pH_Rendah246, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah246 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah246->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah246, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal246 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal246->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah246, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi246 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi246->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal246, EC_Tinggi);
  FuzzyRuleConsequent *Ganti246 = new FuzzyRuleConsequent();
  Ganti246->addOutput(Ganti);
  FuzzyRule *fuzzyRule246 = new FuzzyRule(246,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi246, Ganti246);
  fuzzy->addFuzzyRule(fuzzyRule246);

  //Rules 247
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah247 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah247->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah247 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah247->joinWithAND(DO_Normal_pH_Rendah247, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah247 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah247->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah247, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang247 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang247->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah247, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah247 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah247->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang247, EC_Rendah);
  FuzzyRuleConsequent *Ganti247 = new FuzzyRuleConsequent();
  Ganti247->addOutput(Ganti);
  FuzzyRule *fuzzyRule247 = new FuzzyRule(247,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah247, Ganti247);
  fuzzy->addFuzzyRule(fuzzyRule247);

  //Rules 248
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah248 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah248->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah248 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah248->joinWithAND(DO_Normal_pH_Rendah248, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah248 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah248->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah248, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang248 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang248->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah248, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal248 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal248->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang248, EC_Normal);
  FuzzyRuleConsequent *Ganti248 = new FuzzyRuleConsequent();
  Ganti248->addOutput(Ganti);
  FuzzyRule *fuzzyRule248 = new FuzzyRule(248,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal248, Ganti248);
  fuzzy->addFuzzyRule(fuzzyRule248);

  //Rules 249
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah249 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah249->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah249 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah249->joinWithAND(DO_Normal_pH_Rendah249, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah249 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah249->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah249, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang249 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang249->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah249, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi249 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi249->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang249, EC_Tinggi);
  FuzzyRuleConsequent *Ganti249 = new FuzzyRuleConsequent();
  Ganti249->addOutput(Ganti);
  FuzzyRule *fuzzyRule249 = new FuzzyRule(249,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi249, Ganti249);
  fuzzy->addFuzzyRule(fuzzyRule249);

  //Rules 250
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah250 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah250->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah250 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah250->joinWithAND(DO_Normal_pH_Rendah250, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah250 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah250->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah250, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam250 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam250->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah250, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah250 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah250->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam250, EC_Rendah);
  FuzzyRuleConsequent *Ganti250 = new FuzzyRuleConsequent();
  Ganti250->addOutput(Ganti);
  FuzzyRule *fuzzyRule250 = new FuzzyRule(250,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah250, Ganti250);
  fuzzy->addFuzzyRule(fuzzyRule250);

  //Rules 251
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah251 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah251->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah251 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah251->joinWithAND(DO_Normal_pH_Rendah251, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah251 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah251->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah251, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam251 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam251->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah251, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal251 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal251->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam251, EC_Normal);
  FuzzyRuleConsequent *Ganti251 = new FuzzyRuleConsequent();
  Ganti251->addOutput(Ganti);
  FuzzyRule *fuzzyRule251 = new FuzzyRule(251,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal251, Ganti251);
  fuzzy->addFuzzyRule(fuzzyRule251);

  //Rules 252
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah252 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah252->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah252 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah252->joinWithAND(DO_Normal_pH_Rendah252, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah252 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah252->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah252, Kekeruhan_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam252 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam252->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah252, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi252 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi252->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam252, EC_Tinggi);
  FuzzyRuleConsequent *Ganti252 = new FuzzyRuleConsequent();
  Ganti252->addOutput(Ganti);
  FuzzyRule *fuzzyRule252 = new FuzzyRule(252,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi252, Ganti252);
  fuzzy->addFuzzyRule(fuzzyRule252);

  //Rules 253
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah253 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah253->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah253 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah253->joinWithAND(DO_Normal_pH_Rendah253, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal253 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal253->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah253, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal253 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal253->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal253, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah253 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah253->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal253, EC_Rendah);
  FuzzyRuleConsequent *Ganti253 = new FuzzyRuleConsequent();
  Ganti253->addOutput(Ganti);
  FuzzyRule *fuzzyRule253 = new FuzzyRule(253,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah253, Ganti253);
  fuzzy->addFuzzyRule(fuzzyRule253);

  //Rules 254
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah254 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah254->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah254 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah254->joinWithAND(DO_Normal_pH_Rendah254, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal254 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal254->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah254, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal254 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal254->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal254, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal254= new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal254->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal254, EC_Normal);
  FuzzyRuleConsequent *Ganti254 = new FuzzyRuleConsequent();
  Ganti254->addOutput(Ganti);
  FuzzyRule *fuzzyRule254 = new FuzzyRule(254,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal254, Ganti254);
  fuzzy->addFuzzyRule(fuzzyRule254);

  //Rules 255
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah255 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah255->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah255 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah255->joinWithAND(DO_Normal_pH_Rendah255, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal255 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal255->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah255, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal255 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal255->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal255, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi255 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi255->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal255, EC_Tinggi);
  FuzzyRuleConsequent *Ganti255 = new FuzzyRuleConsequent();
  Ganti255->addOutput(Ganti);
  FuzzyRule *fuzzyRule255 = new FuzzyRule(255,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi255, Ganti255);
  fuzzy->addFuzzyRule(fuzzyRule255);

  //Rules 256
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah256 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah256->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah256 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah256->joinWithAND(DO_Normal_pH_Rendah256, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal256 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal256->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah256, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang256 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang256->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal256, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah256 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah256->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang256, EC_Rendah);
  FuzzyRuleConsequent *Ganti256 = new FuzzyRuleConsequent();
  Ganti256->addOutput(Ganti);
  FuzzyRule *fuzzyRule256 = new FuzzyRule(256,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah256, Ganti256);
  fuzzy->addFuzzyRule(fuzzyRule256);

  //Rules 257
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah257 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah257->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah257 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah257->joinWithAND(DO_Normal_pH_Rendah257, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal257 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal257->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah257, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang257 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang257->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal257, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal257 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal257->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang257, EC_Normal);
  FuzzyRuleConsequent *Ganti257 = new FuzzyRuleConsequent();
  Ganti257->addOutput(Ganti);
  FuzzyRule *fuzzyRule257 = new FuzzyRule(257,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal257, Ganti257);
  fuzzy->addFuzzyRule(fuzzyRule257);

  //Rules 258
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah258 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah258->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah258 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah258->joinWithAND(DO_Normal_pH_Rendah258, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal258 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal258->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah258, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang258 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang258->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal258, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi258 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi258->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang258, EC_Tinggi);
  FuzzyRuleConsequent *Ganti258 = new FuzzyRuleConsequent();
  Ganti258->addOutput(Ganti);
  FuzzyRule *fuzzyRule258 = new FuzzyRule(258,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi258, Ganti258);
  fuzzy->addFuzzyRule(fuzzyRule258);

  //Rules 259
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah259 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah259->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah259 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah259->joinWithAND(DO_Normal_pH_Rendah259, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal259 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal259->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah259, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam259 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam259->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal259, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah259 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah259->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam259, EC_Rendah);
  FuzzyRuleConsequent *Ganti259 = new FuzzyRuleConsequent();
  Ganti259->addOutput(Ganti);
  FuzzyRule *fuzzyRule259 = new FuzzyRule(259,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah259, Ganti259);
  fuzzy->addFuzzyRule(fuzzyRule259);

  //Rules 260
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah260 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah260->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah260 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah260->joinWithAND(DO_Normal_pH_Rendah260, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal260 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal260->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah260, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam260 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam260->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal260, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal260 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal260->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam260, EC_Normal);
  FuzzyRuleConsequent *Ganti260 = new FuzzyRuleConsequent();
  Ganti260->addOutput(Ganti);
  FuzzyRule *fuzzyRule260 = new FuzzyRule(260,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal260, Ganti260);
  fuzzy->addFuzzyRule(fuzzyRule260);

  //Rules 261
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah261 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah261->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah261 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah261->joinWithAND(DO_Normal_pH_Rendah261, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal261 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal261->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah261, Kekeruhan_Normal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam261 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam261->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal261, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi261 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi261->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam261, EC_Tinggi);
  FuzzyRuleConsequent *Ganti261 = new FuzzyRuleConsequent();
  Ganti261->addOutput(Ganti);
  FuzzyRule *fuzzyRule261 = new FuzzyRule(261,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi261, Ganti261);
  fuzzy->addFuzzyRule(fuzzyRule261);

  //Rules 262
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah262 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah262->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah262 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah262->joinWithAND(DO_Normal_pH_Rendah262, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak262 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak262->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah262, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal262 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal262->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak262, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah262 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah262->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal262, EC_Rendah);
  FuzzyRuleConsequent *Ganti262 = new FuzzyRuleConsequent();
  Ganti262->addOutput(Ganti);
  FuzzyRule *fuzzyRule262 = new FuzzyRule(262,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah262, Ganti262);
  fuzzy->addFuzzyRule(fuzzyRule262);

  //Rules 263
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah263 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah263->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah263 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah263->joinWithAND(DO_Normal_pH_Rendah263, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak263 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak263->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah263, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal263 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal263->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak263, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal263 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal263->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal263, EC_Normal);
  FuzzyRuleConsequent *Ganti263 = new FuzzyRuleConsequent();
  Ganti263->addOutput(Ganti);
  FuzzyRule *fuzzyRule263 = new FuzzyRule(263,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal263, Ganti263);
  fuzzy->addFuzzyRule(fuzzyRule263);

  //Rules 264
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah264 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah264->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah264 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah264->joinWithAND(DO_Normal_pH_Rendah264, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak264 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak264->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah264, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal264 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal264->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak264, Jarak_Dangkal);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi264 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi264->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal264, EC_Tinggi);
  FuzzyRuleConsequent *Ganti264 = new FuzzyRuleConsequent();
  Ganti264->addOutput(Ganti);
  FuzzyRule *fuzzyRule264 = new FuzzyRule(264,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi264, Ganti264);
  fuzzy->addFuzzyRule(fuzzyRule264);

  //Rules 265
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah265 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah265->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah265 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah265->joinWithAND(DO_Normal_pH_Rendah265, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak265 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak265->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah265, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang265 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang265->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak265, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah265 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah265->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang265, EC_Rendah);
  FuzzyRuleConsequent *Ganti265 = new FuzzyRuleConsequent();
  Ganti265->addOutput(Ganti);
  FuzzyRule *fuzzyRule265 = new FuzzyRule(265,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah265, Ganti265);
  fuzzy->addFuzzyRule(fuzzyRule265);

  //Rules 266
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah266 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah266->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah266 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah266->joinWithAND(DO_Normal_pH_Rendah266, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak266 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak266->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah266, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang266 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang266->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak266, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal266 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal266->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang266, EC_Normal);
  FuzzyRuleConsequent *Ganti266 = new FuzzyRuleConsequent();
  Ganti266->addOutput(Ganti);
  FuzzyRule *fuzzyRule266 = new FuzzyRule(266,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal266, Ganti266);
  fuzzy->addFuzzyRule(fuzzyRule266);

  //Rules 267
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah267 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah267->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah267 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah267->joinWithAND(DO_Normal_pH_Rendah267, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak267 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak267->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah267, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang267 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang267->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak267, Jarak_Sedang);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi267 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi267->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang267, EC_Tinggi);
  FuzzyRuleConsequent *Ganti267 = new FuzzyRuleConsequent();
  Ganti267->addOutput(Ganti);
  FuzzyRule *fuzzyRule267 = new FuzzyRule(267,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi267, Ganti267);
  fuzzy->addFuzzyRule(fuzzyRule267);

  //Rules 268
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah268 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah268->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah268 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah268->joinWithAND(DO_Normal_pH_Rendah268, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak268 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak268->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah268, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam268 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam268->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak268, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah268 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah268->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam268, EC_Rendah);
  FuzzyRuleConsequent *Ganti268 = new FuzzyRuleConsequent();
  Ganti268->addOutput(Ganti);
  FuzzyRule *fuzzyRule268 = new FuzzyRule(268,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah268, Ganti268);
  fuzzy->addFuzzyRule(fuzzyRule268);

  //Rules 269
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah269 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah269->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah269 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah269->joinWithAND(DO_Normal_pH_Rendah269, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak269 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak269->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah269, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam269 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam269->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak269, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal269 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal269->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam269, EC_Normal);
  FuzzyRuleConsequent *Ganti269 = new FuzzyRuleConsequent();
  Ganti269->addOutput(Ganti);
  FuzzyRule *fuzzyRule269 = new FuzzyRule(269,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal269, Ganti269);
  fuzzy->addFuzzyRule(fuzzyRule269);

  //Rules 270
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah270 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah270->joinWithAND(DO_Normal, pH_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah270 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah270->joinWithAND(DO_Normal_pH_Rendah270, Suhu_Rendah);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak270 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak270->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah270, Kekeruhan_Banyak);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam270 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam270->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak270, Jarak_Dalam);
  FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi270 = new FuzzyRuleAntecedent();
  DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi270->joinWithAND(DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam270, EC_Tinggi);
  FuzzyRuleConsequent *Ganti270 = new FuzzyRuleConsequent();
  Ganti270->addOutput(Ganti);
  FuzzyRule *fuzzyRule270 = new FuzzyRule(270,DO_Normal_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi270, Ganti270);
  fuzzy->addFuzzyRule(fuzzyRule270);

  // Rule 271 (Modified with requested changes)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah271 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah271->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal271 = new FuzzyRuleAntecedent(); 
DO_Normal_pH_Rendah_Suhu_Normal271->joinWithAND(DO_Normal_pH_Rendah271, Suhu_Normal); 
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah271 = new FuzzyRuleAntecedent(); 
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah271->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal271, Kekeruhan_Rendah); 
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal271 = new FuzzyRuleAntecedent(); 
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal271->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah271, Jarak_Dangkal); 
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah271 = new FuzzyRuleAntecedent(); 
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah271->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal271, EC_Rendah); 
FuzzyRuleConsequent *Ganti271 = new FuzzyRuleConsequent();
Ganti271->addOutput(Ganti);
FuzzyRule *fuzzyRule271 = new FuzzyRule(271, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah271, Ganti271);
fuzzy->addFuzzyRule(fuzzyRule271);

// Rule 272 
FuzzyRuleAntecedent *DO_Normal_pH_Rendah272 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah272->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal272 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal272->joinWithAND(DO_Normal_pH_Rendah272, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah272 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah272->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal272, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal272 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal272->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah272, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal272 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal272->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal272, EC_Normal);
FuzzyRuleConsequent *Ganti272 = new FuzzyRuleConsequent();
Ganti272->addOutput(Ganti);
FuzzyRule *fuzzyRule272 = new FuzzyRule(272, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal272, Ganti272);
fuzzy->addFuzzyRule(fuzzyRule272);

// Rule 273
FuzzyRuleAntecedent *DO_Normal_pH_Rendah273 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah273->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal273 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal273->joinWithAND(DO_Normal_pH_Rendah273, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah273 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah273->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal273, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal273 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal273->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah273, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi273 = new FuzzyRuleAntecedent(); 
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi273->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal273, EC_Tinggi);
FuzzyRuleConsequent *Ganti273 = new FuzzyRuleConsequent();
Ganti273->addOutput(Ganti);
FuzzyRule *fuzzyRule273 = new FuzzyRule(273, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi273, Ganti273);
fuzzy->addFuzzyRule(fuzzyRule273);

// Rule 274 (Modified pattern with "Jarak_Sedang")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah274 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah274->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal274 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal274->joinWithAND(DO_Normal_pH_Rendah274, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah274 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah274->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal274, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang274 = new FuzzyRuleAntecedent(); // Change "Jarak_Dangkal" to "Jarak_Sedang"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang274->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah274, Jarak_Sedang); // Change "Jarak_Dangkal" to "Jarak_Sedang"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah274 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah274->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang274, EC_Rendah);
FuzzyRuleConsequent *Ganti274 = new FuzzyRuleConsequent();
Ganti274->addOutput(Ganti);
FuzzyRule *fuzzyRule274 = new FuzzyRule(274, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah274, Ganti274);
fuzzy->addFuzzyRule(fuzzyRule274);

// Rule 275 (Modified pattern with "Jarak_Sedang")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah275 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah275->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal275 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal275->joinWithAND(DO_Normal_pH_Rendah275, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah275 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah275->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal275, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang275 = new FuzzyRuleAntecedent(); // Change "Jarak_Dangkal" to "Jarak_Sedang"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang275->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah275, Jarak_Sedang); // Change "Jarak_Dangkal" to "Jarak_Sedang"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal275 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal275->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang275, EC_Normal);
FuzzyRuleConsequent *Ganti275 = new FuzzyRuleConsequent();
Ganti275->addOutput(Ganti);
FuzzyRule *fuzzyRule275 = new FuzzyRule(275, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal275, Ganti275);
fuzzy->addFuzzyRule(fuzzyRule275);

// Rule 276 (Modified pattern with "Jarak_Sedang")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah276 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah276->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal276 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal276->joinWithAND(DO_Normal_pH_Rendah276, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah276 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah276->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal276, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang276 = new FuzzyRuleAntecedent(); // Change "Jarak_Dangkal" to "Jarak_Sedang"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang276->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah276, Jarak_Sedang); // Change "Jarak_Dangkal" to "Jarak_Sedang"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi276 = new FuzzyRuleAntecedent(); // Change "EC_Normal" to "EC_Tinggi"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi276->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang276, EC_Tinggi); // Change "EC_Normal" to "EC_Tinggi"
FuzzyRuleConsequent *Ganti276 = new FuzzyRuleConsequent();
Ganti276->addOutput(Ganti);
FuzzyRule *fuzzyRule276 = new FuzzyRule(276, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi276, Ganti276);
fuzzy->addFuzzyRule(fuzzyRule276);

// Rule 277 (Modified pattern with "Jarak_Dalam")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah277 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah277->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal277 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal277->joinWithAND(DO_Normal_pH_Rendah277, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah277 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah277->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal277, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam277 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam277->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah277, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah277 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah277->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam277, EC_Rendah);
FuzzyRuleConsequent *Ganti277 = new FuzzyRuleConsequent();
Ganti277->addOutput(Ganti);
FuzzyRule *fuzzyRule277 = new FuzzyRule(277, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah277, Ganti277);
fuzzy->addFuzzyRule(fuzzyRule277);

// Rule 278 (Modified pattern with "Jarak_Dalam")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah278 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah278->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal278 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal278->joinWithAND(DO_Normal_pH_Rendah278, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah278 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah278->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal278, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam278 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam278->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah278, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal278 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal278->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam278, EC_Normal);
FuzzyRuleConsequent *Ganti278 = new FuzzyRuleConsequent();
Ganti278->addOutput(Ganti);
FuzzyRule *fuzzyRule278 = new FuzzyRule(278, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal278, Ganti278);
fuzzy->addFuzzyRule(fuzzyRule278);

// Rule 279 (Modified pattern with "Jarak_Dalam")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah279 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah279->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal279 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal279->joinWithAND(DO_Normal_pH_Rendah279, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah279 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah279->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal279, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam279 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam279->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah279, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi279 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi279->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam279, EC_Tinggi);
FuzzyRuleConsequent *Ganti279 = new FuzzyRuleConsequent();
Ganti279->addOutput(Ganti);
FuzzyRule *fuzzyRule279 = new FuzzyRule(279, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi279, Ganti279);
fuzzy->addFuzzyRule(fuzzyRule279);

// Rule 280 (Modified "Kekeruhan_Rendah" to "Kekeruhan_Normal", "Jarak_Dalam" to "Jarak_Dangkal", and "EC_Tinggi" to "EC_Rendah")
FuzzyRuleAntecedent *DO_Normal_pH_Rendah280 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah280->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal280 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal280->joinWithAND(DO_Normal_pH_Rendah280, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal280 = new FuzzyRuleAntecedent(); // Change "Kekeruhan_Rendah" to "Kekeruhan_Normal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal280->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal280, Kekeruhan_Normal); // Change "Kekeruhan_Rendah" to "Kekeruhan_Normal"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal280 = new FuzzyRuleAntecedent(); // Change "Jarak_Dalam" to "Jarak_Dangkal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal280->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal280, Jarak_Dangkal); // Change "Jarak_Dalam" to "Jarak_Dangkal"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah280 = new FuzzyRuleAntecedent(); // Change "EC_Tinggi" to "EC_Rendah"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah280->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal280, EC_Rendah); // Change "EC_Tinggi" to "EC_Rendah"
FuzzyRuleConsequent *Ganti280 = new FuzzyRuleConsequent();
Ganti280->addOutput(Ganti);
FuzzyRule *fuzzyRule280 = new FuzzyRule(280, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah280, Ganti280);
fuzzy->addFuzzyRule(fuzzyRule280);

// Rule 281 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah281 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah281->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal281 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal281->joinWithAND(DO_Normal_pH_Rendah281, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal281 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal281->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal281, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal281 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal281->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal281, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal281 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal281->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal281, EC_Normal);
FuzzyRuleConsequent *Ganti281 = new FuzzyRuleConsequent();
Ganti281->addOutput(Ganti);
FuzzyRule *fuzzyRule281 = new FuzzyRule(281, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal281, Ganti281);
fuzzy->addFuzzyRule(fuzzyRule281);

// Rule 282 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah282 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah282->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal282 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal282->joinWithAND(DO_Normal_pH_Rendah282, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal282 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal282->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal282, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal282 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal282->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal282, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi282 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi282->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal282, EC_Tinggi);
FuzzyRuleConsequent *Ganti282 = new FuzzyRuleConsequent();
Ganti282->addOutput(Ganti);
FuzzyRule *fuzzyRule282 = new FuzzyRule(282, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi282, Ganti282);
fuzzy->addFuzzyRule(fuzzyRule282);

// Rule 283 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah283 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah283->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal283 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal283->joinWithAND(DO_Normal_pH_Rendah283, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal283 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal283->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal283, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang283 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang283->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal283, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah283 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah283->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang283, EC_Rendah);
FuzzyRuleConsequent *Ganti283 = new FuzzyRuleConsequent();
Ganti283->addOutput(Ganti);
FuzzyRule *fuzzyRule283 = new FuzzyRule(283, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah283, Ganti283);
fuzzy->addFuzzyRule(fuzzyRule283);

// Rule 284 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah284 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah284->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal284 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal284->joinWithAND(DO_Normal_pH_Rendah284, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal284 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal284->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal284, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang284 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang284->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal284, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal284 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal284->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang284, EC_Normal);
FuzzyRuleConsequent *Ganti284 = new FuzzyRuleConsequent();
Ganti284->addOutput(Ganti);
FuzzyRule *fuzzyRule284 = new FuzzyRule(284, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal284, Ganti284);
fuzzy->addFuzzyRule(fuzzyRule284);

// Rule 285 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah285 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah285->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal285 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal285->joinWithAND(DO_Normal_pH_Rendah285, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal285 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal285->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal285, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang285 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang285->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal285, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi285 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi285->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang285, EC_Tinggi);
FuzzyRuleConsequent *Ganti285 = new FuzzyRuleConsequent();
Ganti285->addOutput(Ganti);
FuzzyRule *fuzzyRule285 = new FuzzyRule(285, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi285, Ganti285);
fuzzy->addFuzzyRule(fuzzyRule285);

// Rule 286 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah286 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah286->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal286 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal286->joinWithAND(DO_Normal_pH_Rendah286, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal286 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal286->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal286, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam286 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam286->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal286, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah286 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah286->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam286, EC_Rendah);
FuzzyRuleConsequent *Ganti286 = new FuzzyRuleConsequent();
Ganti286->addOutput(Ganti);
FuzzyRule *fuzzyRule286 = new FuzzyRule(286, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah286, Ganti286);
fuzzy->addFuzzyRule(fuzzyRule286);

// Rule 287 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah287 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah287->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal287 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal287->joinWithAND(DO_Normal_pH_Rendah287, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal287 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal287->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal287, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam287 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam287->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal287, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal287 = new FuzzyRuleAntecedent(); // Change "EC_Rendah" to "EC_Normal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal287->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam287, EC_Normal); // Change "EC_Rendah" to "EC_Normal"
FuzzyRuleConsequent *Ganti287 = new FuzzyRuleConsequent();
Ganti287->addOutput(Ganti);
FuzzyRule *fuzzyRule287 = new FuzzyRule(287, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal287, Ganti287);
fuzzy->addFuzzyRule(fuzzyRule287);

// Rule 288 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah288 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah288->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal288 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal288->joinWithAND(DO_Normal_pH_Rendah288, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal288 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal288->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal288, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam288 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam288->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal288, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi288 = new FuzzyRuleAntecedent(); // Change "EC_Normal" to "EC_Tinggi"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi288->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam288, EC_Tinggi); // Change "EC_Normal" to "EC_Tinggi"
FuzzyRuleConsequent *Ganti288 = new FuzzyRuleConsequent();
Ganti288->addOutput(Ganti);
FuzzyRule *fuzzyRule288 = new FuzzyRule(288, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi288, Ganti288);
fuzzy->addFuzzyRule(fuzzyRule288);

// Rule 289 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah289 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah289->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal289 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal289->joinWithAND(DO_Normal_pH_Rendah289, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak289 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak289->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal289, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal289 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal289->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak289, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah289 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah289->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal289, EC_Rendah);
FuzzyRuleConsequent *Ganti289 = new FuzzyRuleConsequent();
Ganti289->addOutput(Ganti);
FuzzyRule *fuzzyRule289 = new FuzzyRule(289, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah289, Ganti289);
fuzzy->addFuzzyRule(fuzzyRule289);

// Rule 290 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah290 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah290->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal290 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal290->joinWithAND(DO_Normal_pH_Rendah290, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak290 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak290->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal290, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal290 = new FuzzyRuleAntecedent(); // Change "Jarak_Dalam" to "Jarak_Dangkal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal290->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak290, Jarak_Dangkal); // Change "Jarak_Dalam" to "Jarak_Dangkal"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal290 = new FuzzyRuleAntecedent(); // Change "EC_Tinggi" to "EC_Normal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal290->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal290, EC_Normal); // Change "EC_Tinggi" to "EC_Normal"
FuzzyRuleConsequent *Ganti290 = new FuzzyRuleConsequent();
Ganti290->addOutput(Ganti);
FuzzyRule *fuzzyRule290 = new FuzzyRule(290, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal290, Ganti290);
fuzzy->addFuzzyRule(fuzzyRule290);

// Rule 291 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah291 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah291->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal291 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal291->joinWithAND(DO_Normal_pH_Rendah291, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak291 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak291->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal291, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal291 = new FuzzyRuleAntecedent(); // Change "Jarak_Dangkal" to "Jarak_Sedang"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal291->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak291, Jarak_Sedang); // Change "Jarak_Dangkal" to "Jarak_Sedang"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi291 = new FuzzyRuleAntecedent(); // Change "EC_Normal" to "EC_Tinggi"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi291->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal291, EC_Tinggi); // Change "EC_Normal" to "EC_Tinggi"
FuzzyRuleConsequent *Ganti291 = new FuzzyRuleConsequent();
Ganti291->addOutput(Ganti);
FuzzyRule *fuzzyRule291 = new FuzzyRule(291, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi291, Ganti291);
fuzzy->addFuzzyRule(fuzzyRule291);

// Rule 292 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah292 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah292->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal292 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal292->joinWithAND(DO_Normal_pH_Rendah292, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak292 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak292->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal292, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang292 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang292->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak292, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah292 = new FuzzyRuleAntecedent(); // Change "EC_Tinggi" to "EC_Rendah"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah292->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang292, EC_Rendah); // Change "EC_Tinggi" to "EC_Rendah"
FuzzyRuleConsequent *Ganti292 = new FuzzyRuleConsequent();
Ganti292->addOutput(Ganti);
FuzzyRule *fuzzyRule292 = new FuzzyRule(292, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah292, Ganti292);
fuzzy->addFuzzyRule(fuzzyRule292);

// Rule 293 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah293 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah293->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal293 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal293->joinWithAND(DO_Normal_pH_Rendah293, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak293 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak293->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal293, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang293 = new FuzzyRuleAntecedent(); // Change "Jarak_Dalam" to "Jarak_Sedang"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang293->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak293, Jarak_Sedang); // Change "Jarak_Dalam" to "Jarak_Sedang"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal293 = new FuzzyRuleAntecedent(); // Change "EC_Rendah" to "EC_Normal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal293->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang293, EC_Normal); // Change "EC_Rendah" to "EC_Normal"
FuzzyRuleConsequent *Ganti293 = new FuzzyRuleConsequent();
Ganti293->addOutput(Ganti);
FuzzyRule *fuzzyRule293 = new FuzzyRule(293, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal293, Ganti293);
fuzzy->addFuzzyRule(fuzzyRule293);

// Rule 294 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah294 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah294->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal294 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal294->joinWithAND(DO_Normal_pH_Rendah294, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak294 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak294->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal294, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang294 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dangkal"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang294->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak294, Jarak_Dangkal); // Change "Jarak_Sedang" to "Jarak_Dangkal"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi294 = new FuzzyRuleAntecedent(); // Change "EC_Normal" to "EC_Tinggi"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi294->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang294, EC_Tinggi); // Change "EC_Normal" to "EC_Tinggi"
FuzzyRuleConsequent *Ganti294 = new FuzzyRuleConsequent();
Ganti294->addOutput(Ganti);
FuzzyRule *fuzzyRule294 = new FuzzyRule(294, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi294, Ganti294);
fuzzy->addFuzzyRule(fuzzyRule294);

// Rule 295 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah295 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah295->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal295 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal295->joinWithAND(DO_Normal_pH_Rendah295, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak295 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak295->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal295, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam295 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam295->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak295, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah295 = new FuzzyRuleAntecedent(); // Change "EC_Tinggi" to "EC_Rendah"
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah295->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam295, EC_Rendah); // Change "EC_Tinggi" to "EC_Rendah"
FuzzyRuleConsequent *Ganti295 = new FuzzyRuleConsequent();
Ganti295->addOutput(Ganti);
FuzzyRule *fuzzyRule295 = new FuzzyRule(295, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah295, Ganti295);
fuzzy->addFuzzyRule(fuzzyRule295);

// Rule 296 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah296 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah296->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal296 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal296->joinWithAND(DO_Normal_pH_Rendah296, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak296 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak296->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal296, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam296 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam296->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak296, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal296 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal296->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam296, EC_Normal);
FuzzyRuleConsequent *Ganti296 = new FuzzyRuleConsequent();
Ganti296->addOutput(Ganti);
FuzzyRule *fuzzyRule296 = new FuzzyRule(296, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal296, Ganti296);
fuzzy->addFuzzyRule(fuzzyRule296);

// Rule 297 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah297 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah297->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal297 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal297->joinWithAND(DO_Normal_pH_Rendah297, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak297 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak297->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal297, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam297 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam297->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak297, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi297 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi297->joinWithAND(DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam297, EC_Tinggi);
FuzzyRuleConsequent *Ganti297 = new FuzzyRuleConsequent();
Ganti297->addOutput(Ganti);
FuzzyRule *fuzzyRule297 = new FuzzyRule(297, DO_Normal_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi297, Ganti297);
fuzzy->addFuzzyRule(fuzzyRule297);

// Rule 298 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah298 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah298->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak298 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak298->joinWithAND(DO_Normal_pH_Rendah298, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah298 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah298->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak298, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal298 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal298->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah298, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah298 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah298->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal298, EC_Rendah);
FuzzyRuleConsequent *Ganti298 = new FuzzyRuleConsequent();
Ganti298->addOutput(Ganti);
FuzzyRule *fuzzyRule298 = new FuzzyRule(298, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah298, Ganti298);
fuzzy->addFuzzyRule(fuzzyRule298);

// Rule 299 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah299 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah299->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak299 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak299->joinWithAND(DO_Normal_pH_Rendah299, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah299 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah299->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak299, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal299 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal299->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah299, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal299 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal299->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal299, EC_Normal);
FuzzyRuleConsequent *Ganti299 = new FuzzyRuleConsequent();
Ganti299->addOutput(Ganti);
FuzzyRule *fuzzyRule299 = new FuzzyRule(299, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal299, Ganti299);
fuzzy->addFuzzyRule(fuzzyRule299);

// Rule 300 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah300 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah300->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak300 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak300->joinWithAND(DO_Normal_pH_Rendah300, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah300 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah300->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak300, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal300 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal300->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah300, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi300 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi300->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal300, EC_Tinggi);
FuzzyRuleConsequent *Ganti300 = new FuzzyRuleConsequent();
Ganti300->addOutput(Ganti);
FuzzyRule *fuzzyRule300 = new FuzzyRule(300, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi300, Ganti300);
fuzzy->addFuzzyRule(fuzzyRule300);

// Rule 301 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah301 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah301->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak301 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak301->joinWithAND(DO_Normal_pH_Rendah301, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah301 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah301->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak301, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang301 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang301->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah301, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah301 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah301->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang301, EC_Rendah);
FuzzyRuleConsequent *Ganti301 = new FuzzyRuleConsequent();
Ganti301->addOutput(Ganti);
FuzzyRule *fuzzyRule301 = new FuzzyRule(301, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah301, Ganti301);
fuzzy->addFuzzyRule(fuzzyRule301);

// Rule 302 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah302 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah302->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak302 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak302->joinWithAND(DO_Normal_pH_Rendah302, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah302 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah302->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak302, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang302 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang302->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah302, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal302 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal302->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang302, EC_Normal);
FuzzyRuleConsequent *Ganti302 = new FuzzyRuleConsequent();
Ganti302->addOutput(Ganti);
FuzzyRule *fuzzyRule302 = new FuzzyRule(302, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal302, Ganti302);
fuzzy->addFuzzyRule(fuzzyRule302);

// Rule 303 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah303 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah303->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak303 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak303->joinWithAND(DO_Normal_pH_Rendah303, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah303 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah303->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak303, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang303 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang303->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah303, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi303 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi303->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang303, EC_Tinggi);
FuzzyRuleConsequent *Ganti303 = new FuzzyRuleConsequent();
Ganti303->addOutput(Ganti);
FuzzyRule *fuzzyRule303 = new FuzzyRule(303, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi303, Ganti303);
fuzzy->addFuzzyRule(fuzzyRule303);

// Rule 304 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah304 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah304->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak304 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak304->joinWithAND(DO_Normal_pH_Rendah304, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah304 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah304->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak304, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam304 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam304->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah304, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah304 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah304->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam304, EC_Rendah);
FuzzyRuleConsequent *Ganti304 = new FuzzyRuleConsequent();
Ganti304->addOutput(Ganti);
FuzzyRule *fuzzyRule304 = new FuzzyRule(304, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah304, Ganti304);
fuzzy->addFuzzyRule(fuzzyRule304);

// Rule 305 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah305 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah305->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak305 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak305->joinWithAND(DO_Normal_pH_Rendah305, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah305 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah305->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak305, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam305 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam305->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah305, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal305 = new FuzzyRuleAntecedent(); // Change "EC_Rendah" to "EC_Normal"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal305->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam305, EC_Normal); // Change "EC_Rendah" to "EC_Normal"
FuzzyRuleConsequent *Ganti305 = new FuzzyRuleConsequent();
Ganti305->addOutput(Ganti);
FuzzyRule *fuzzyRule305 = new FuzzyRule(305, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal305, Ganti305);
fuzzy->addFuzzyRule(fuzzyRule305);

// Rule 306 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah306 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah306->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak306 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak306->joinWithAND(DO_Normal_pH_Rendah306, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah306 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah306->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak306, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam306 = new FuzzyRuleAntecedent(); // Change "Jarak_Sedang" to "Jarak_Dalam"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam306->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah306, Jarak_Dalam); // Change "Jarak_Sedang" to "Jarak_Dalam"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi306 = new FuzzyRuleAntecedent(); // Change "EC_Rendah" to "EC_Tinggi"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi306->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam306, EC_Tinggi); // Change "EC_Rendah" to "EC_Tinggi"
FuzzyRuleConsequent *Ganti306 = new FuzzyRuleConsequent();
Ganti306->addOutput(Ganti);
FuzzyRule *fuzzyRule306 = new FuzzyRule(306, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi306, Ganti306);
fuzzy->addFuzzyRule(fuzzyRule306);

// Rule 307 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah307 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah307->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak307 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak307->joinWithAND(DO_Normal_pH_Rendah307, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal307 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal307->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak307, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal307 = new FuzzyRuleAntecedent(); // Change "Jarak_Rendah" to "Jarak_Dangkal"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal307->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal307, Jarak_Dangkal); // Change "Jarak_Rendah" to "Jarak_Dangkal"
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah307 = new FuzzyRuleAntecedent(); // Change "EC_Tinggi" to "EC_Rendah"
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah307->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal307, EC_Rendah); // Change "EC_Tinggi" to "EC_Rendah"
FuzzyRuleConsequent *Ganti307 = new FuzzyRuleConsequent();
Ganti307->addOutput(Ganti);
FuzzyRule *fuzzyRule307 = new FuzzyRule(307, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah307, Ganti307);
fuzzy->addFuzzyRule(fuzzyRule307);

// Rule 308 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah308 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah308->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak308 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak308->joinWithAND(DO_Normal_pH_Rendah308, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal308 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal308->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak308, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal308 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal308->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal308, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal308 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal308->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal308, EC_Normal);
FuzzyRuleConsequent *Ganti308 = new FuzzyRuleConsequent();
Ganti308->addOutput(Ganti);
FuzzyRule *fuzzyRule308 = new FuzzyRule(308, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal308, Ganti308);
fuzzy->addFuzzyRule(fuzzyRule308);

// Rule 309 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah309 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah309->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak309 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak309->joinWithAND(DO_Normal_pH_Rendah309, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal309 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal309->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak309, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal309 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal309->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal309, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi309 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi309->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal309, EC_Tinggi);
FuzzyRuleConsequent *Ganti309 = new FuzzyRuleConsequent();
Ganti309->addOutput(Ganti);
FuzzyRule *fuzzyRule309 = new FuzzyRule(309, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi309, Ganti309);
fuzzy->addFuzzyRule(fuzzyRule309);

// Rule 310 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah310 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah310->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak310 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak310->joinWithAND(DO_Normal_pH_Rendah310, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal310 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal310->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak310, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang310 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang310->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal310, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah310 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah310->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang310, EC_Rendah);
FuzzyRuleConsequent *Ganti310 = new FuzzyRuleConsequent();
Ganti310->addOutput(Ganti);
FuzzyRule *fuzzyRule310 = new FuzzyRule(310, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah310, Ganti310);
fuzzy->addFuzzyRule(fuzzyRule310);

// Rule 311 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah311 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah311->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak311 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak311->joinWithAND(DO_Normal_pH_Rendah311, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal311 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal311->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak311, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang311 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang311->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal311, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal311 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal311->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang311, EC_Normal);
FuzzyRuleConsequent *Ganti311 = new FuzzyRuleConsequent();
Ganti311->addOutput(Ganti);
FuzzyRule *fuzzyRule311 = new FuzzyRule(311, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal311, Ganti311);
fuzzy->addFuzzyRule(fuzzyRule311);

// Rule 312 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah312 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah312->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak312 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak312->joinWithAND(DO_Normal_pH_Rendah312, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal312 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal312->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak312, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang312 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang312->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal312, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi312 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi312->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang312, EC_Tinggi);
FuzzyRuleConsequent *Ganti312 = new FuzzyRuleConsequent();
Ganti312->addOutput(Ganti);
FuzzyRule *fuzzyRule312 = new FuzzyRule(312, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi312, Ganti312);
fuzzy->addFuzzyRule(fuzzyRule312);

// Rule 313 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah313 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah313->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak313 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak313->joinWithAND(DO_Normal_pH_Rendah313, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal313 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal313->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak313, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam313 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam313->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal313, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah313 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah313->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam313, EC_Rendah);
FuzzyRuleConsequent *Ganti313 = new FuzzyRuleConsequent();
Ganti313->addOutput(Ganti);
FuzzyRule *fuzzyRule313 = new FuzzyRule(313, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah313, Ganti313);
fuzzy->addFuzzyRule(fuzzyRule313);

// Rule 314 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah314 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah314->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak314 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak314->joinWithAND(DO_Normal_pH_Rendah314, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal314 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal314->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak314, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam314 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam314->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal314, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal314 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal314->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam314, EC_Normal);
FuzzyRuleConsequent *Ganti314 = new FuzzyRuleConsequent();
Ganti314->addOutput(Ganti);
FuzzyRule *fuzzyRule314 = new FuzzyRule(314, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal314, Ganti314);
fuzzy->addFuzzyRule(fuzzyRule314);

// Rule 315 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah315 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah315->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak315 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak315->joinWithAND(DO_Normal_pH_Rendah315, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal315 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal315->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak315, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam315 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam315->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal315, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi315 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi315->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam315, EC_Tinggi);
FuzzyRuleConsequent *Ganti315 = new FuzzyRuleConsequent();
Ganti315->addOutput(Ganti);
FuzzyRule *fuzzyRule315 = new FuzzyRule(315, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi315, Ganti315);
fuzzy->addFuzzyRule(fuzzyRule315);

// Rule 316 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah316 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah316->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak316 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak316->joinWithAND(DO_Normal_pH_Rendah316, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak316 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak316->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak316, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal316 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal316->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak316, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah316 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah316->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal316, EC_Rendah);
FuzzyRuleConsequent *Ganti316 = new FuzzyRuleConsequent();
Ganti316->addOutput(Ganti);
FuzzyRule *fuzzyRule316 = new FuzzyRule(316, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah316, Ganti316);
fuzzy->addFuzzyRule(fuzzyRule316);

// Rule 317 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah317 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah317->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak317 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak317->joinWithAND(DO_Normal_pH_Rendah317, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak317 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak317->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak317, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal317 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal317->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak317, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal317 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal317->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal317, EC_Normal);
FuzzyRuleConsequent *Ganti317 = new FuzzyRuleConsequent();
Ganti317->addOutput(Ganti);
FuzzyRule *fuzzyRule317 = new FuzzyRule(317, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal317, Ganti317);
fuzzy->addFuzzyRule(fuzzyRule317);

// Rule 318 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah318 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah318->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak318 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak318->joinWithAND(DO_Normal_pH_Rendah318, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak318 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak318->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak318, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal318 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal318->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak318, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi318 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi318->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal318, EC_Tinggi);
FuzzyRuleConsequent *Ganti318 = new FuzzyRuleConsequent();
Ganti318->addOutput(Ganti);
FuzzyRule *fuzzyRule318 = new FuzzyRule(318, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi318, Ganti318);
fuzzy->addFuzzyRule(fuzzyRule318);

// Rule 319 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah319 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah319->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak319 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak319->joinWithAND(DO_Normal_pH_Rendah319, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak319 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak319->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak319, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang319 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang319->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak319, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah319 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah319->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang319, EC_Rendah);
FuzzyRuleConsequent *Ganti319 = new FuzzyRuleConsequent();
Ganti319->addOutput(Ganti);
FuzzyRule *fuzzyRule319 = new FuzzyRule(319, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah319, Ganti319);
fuzzy->addFuzzyRule(fuzzyRule319);

// Rule 320 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah320 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah320->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak320 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak320->joinWithAND(DO_Normal_pH_Rendah320, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak320 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak320->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak320, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang320 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang320->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak320, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal320 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal320->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang320, EC_Normal);
FuzzyRuleConsequent *Ganti320 = new FuzzyRuleConsequent();
Ganti320->addOutput(Ganti);
FuzzyRule *fuzzyRule320 = new FuzzyRule(320, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal320, Ganti320);
fuzzy->addFuzzyRule(fuzzyRule320);

// Rule 321 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah321 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah321->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak321 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak321->joinWithAND(DO_Normal_pH_Rendah321, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak321 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak321->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak321, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang321 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang321->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak321, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi321 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi321->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang321, EC_Tinggi);
FuzzyRuleConsequent *Ganti321 = new FuzzyRuleConsequent();
Ganti321->addOutput(Ganti);
FuzzyRule *fuzzyRule321 = new FuzzyRule(321, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi321, Ganti321);
fuzzy->addFuzzyRule(fuzzyRule321);

// Rule 322 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah322 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah322->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak322 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak322->joinWithAND(DO_Normal_pH_Rendah322, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak322 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak322->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak322, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam322 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam322->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak322, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah322 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah322->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam322, EC_Rendah);
FuzzyRuleConsequent *Ganti322 = new FuzzyRuleConsequent();
Ganti322->addOutput(Ganti);
FuzzyRule *fuzzyRule322 = new FuzzyRule(322, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah322, Ganti322);
fuzzy->addFuzzyRule(fuzzyRule322);

// Rule 323 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah323 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah323->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak323 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak323->joinWithAND(DO_Normal_pH_Rendah323, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak323 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak323->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak323, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam323 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam323->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak323, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal323 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal323->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam323, EC_Normal);
FuzzyRuleConsequent *Ganti323 = new FuzzyRuleConsequent();
Ganti323->addOutput(Ganti);
FuzzyRule *fuzzyRule323 = new FuzzyRule(323, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal323, Ganti323);
fuzzy->addFuzzyRule(fuzzyRule323);

// Rule 324 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Rendah324 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah324->joinWithAND(DO_Normal, pH_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak324 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak324->joinWithAND(DO_Normal_pH_Rendah324, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak324 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak324->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak324, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam324 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam324->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak324, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi324 = new FuzzyRuleAntecedent();
DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi324->joinWithAND(DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam324, EC_Tinggi);
FuzzyRuleConsequent *Ganti324 = new FuzzyRuleConsequent();
Ganti324->addOutput(Ganti);
FuzzyRule *fuzzyRule324 = new FuzzyRule(324, DO_Normal_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi324, Ganti324);
fuzzy->addFuzzyRule(fuzzyRule324);

// Rule 325 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal325 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal325->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah325 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah325->joinWithAND(DO_Normal_pH_Normal325, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah325 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah325->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah325, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal325 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal325->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah325, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah325 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah325->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal325, EC_Rendah);
FuzzyRuleConsequent *Ganti325 = new FuzzyRuleConsequent();
Ganti325->addOutput(Ganti);
FuzzyRule *fuzzyRule325 = new FuzzyRule(325, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah325, Ganti325);
fuzzy->addFuzzyRule(fuzzyRule325);

// Rule 326 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal326 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal326->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah326 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah326->joinWithAND(DO_Normal_pH_Normal326, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah326 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah326->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah326, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal326 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal326->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah326, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal326 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal326->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal326, EC_Normal);
FuzzyRuleConsequent *Ganti326 = new FuzzyRuleConsequent();
Ganti326->addOutput(Ganti);
FuzzyRule *fuzzyRule326 = new FuzzyRule(326, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal326, Ganti326);
fuzzy->addFuzzyRule(fuzzyRule326);

// Rule 327 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal327 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal327->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah327 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah327->joinWithAND(DO_Normal_pH_Normal327, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah327 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah327->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah327, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal327 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal327->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah327, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi327 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi327->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal327, EC_Tinggi);
FuzzyRuleConsequent *Ganti327 = new FuzzyRuleConsequent();
Ganti327->addOutput(Ganti);
FuzzyRule *fuzzyRule327 = new FuzzyRule(327, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi327, Ganti327);
fuzzy->addFuzzyRule(fuzzyRule327);

// Rule 328 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal328 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal328->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah328 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah328->joinWithAND(DO_Normal_pH_Normal328, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah328 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah328->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah328, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang328 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang328->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah328, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah328 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah328->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang328, EC_Rendah);
FuzzyRuleConsequent *Ganti328 = new FuzzyRuleConsequent();
Ganti328->addOutput(Ganti);
FuzzyRule *fuzzyRule328 = new FuzzyRule(328, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah328, Ganti328);
fuzzy->addFuzzyRule(fuzzyRule328);

// Rule 329 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal329 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal329->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah329 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah329->joinWithAND(DO_Normal_pH_Normal329, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah329 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah329->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah329, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang329 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang329->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah329, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal329 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal329->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang329, EC_Normal);
FuzzyRuleConsequent *Ganti329 = new FuzzyRuleConsequent();
Ganti329->addOutput(Ganti);
FuzzyRule *fuzzyRule329 = new FuzzyRule(329, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal329, Ganti329);
fuzzy->addFuzzyRule(fuzzyRule329);

// Rule 330 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal330 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal330->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah330 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah330->joinWithAND(DO_Normal_pH_Normal330, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah330 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah330->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah330, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang330 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang330->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah330, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi330 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi330->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang330, EC_Tinggi);
FuzzyRuleConsequent *Ganti330 = new FuzzyRuleConsequent();
Ganti330->addOutput(Ganti);
FuzzyRule *fuzzyRule330 = new FuzzyRule(330, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi330, Ganti330);
fuzzy->addFuzzyRule(fuzzyRule330);

// Rule 331 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal331 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal331->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah331 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah331->joinWithAND(DO_Normal_pH_Normal331, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah331 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah331->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah331, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam331 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam331->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah331, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah331 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah331->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam331, EC_Rendah);
FuzzyRuleConsequent *Ganti331 = new FuzzyRuleConsequent();
Ganti331->addOutput(Ganti);
FuzzyRule *fuzzyRule331 = new FuzzyRule(331, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah331, Ganti331);
fuzzy->addFuzzyRule(fuzzyRule331);

// Rule 332 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal332 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal332->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah332 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah332->joinWithAND(DO_Normal_pH_Normal332, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah332 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah332->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah332, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam332 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam332->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah332, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal332 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal332->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam332, EC_Normal);
FuzzyRuleConsequent *Ganti332 = new FuzzyRuleConsequent();
Ganti332->addOutput(Ganti);
FuzzyRule *fuzzyRule332 = new FuzzyRule(332, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal332, Ganti332);
fuzzy->addFuzzyRule(fuzzyRule332);

// Rule 333 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal333 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal333->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah333 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah333->joinWithAND(DO_Normal_pH_Normal333, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah333 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah333->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah333, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam333 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam333->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah333, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi333 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi333->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam333, EC_Tinggi);
FuzzyRuleConsequent *Ganti333 = new FuzzyRuleConsequent();
Ganti333->addOutput(Ganti);
FuzzyRule *fuzzyRule333 = new FuzzyRule(333, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi333, Ganti333);
fuzzy->addFuzzyRule(fuzzyRule333);

// Rule 334 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal334 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal334->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah334 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah334->joinWithAND(DO_Normal_pH_Normal334, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal334 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal334->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah334, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal334 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal334->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal334, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah334 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah334->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal334, EC_Rendah);
FuzzyRuleConsequent *Ganti334 = new FuzzyRuleConsequent();
Ganti334->addOutput(Ganti);
FuzzyRule *fuzzyRule334 = new FuzzyRule(334, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah334, Ganti334);
fuzzy->addFuzzyRule(fuzzyRule334);

// Rule 335 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal335 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal335->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah335 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah335->joinWithAND(DO_Normal_pH_Normal335, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal335 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal335->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah335, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal335 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal335->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal335, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal335 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal335->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal335, EC_Normal);
FuzzyRuleConsequent *Ganti335 = new FuzzyRuleConsequent();
Ganti335->addOutput(Ganti);
FuzzyRule *fuzzyRule335 = new FuzzyRule(335, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal335, Ganti335);
fuzzy->addFuzzyRule(fuzzyRule335);

// Rule 336 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal336 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal336->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah336 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah336->joinWithAND(DO_Normal_pH_Normal336, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal336 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal336->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah336, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal336 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal336->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal336, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi336 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi336->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal336, EC_Tinggi);
FuzzyRuleConsequent *Ganti336 = new FuzzyRuleConsequent();
Ganti336->addOutput(Ganti);
FuzzyRule *fuzzyRule336 = new FuzzyRule(336, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi336, Ganti336);
fuzzy->addFuzzyRule(fuzzyRule336);

// Rule 337 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal337 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal337->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah337 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah337->joinWithAND(DO_Normal_pH_Normal337, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal337 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal337->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah337, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang337 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang337->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal337, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah337 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah337->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang337, EC_Rendah);
FuzzyRuleConsequent *Ganti337 = new FuzzyRuleConsequent();
Ganti337->addOutput(Ganti);
FuzzyRule *fuzzyRule337 = new FuzzyRule(337, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah337, Ganti337);
fuzzy->addFuzzyRule(fuzzyRule337);

// Rule 338 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal338 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal338->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah338 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah338->joinWithAND(DO_Normal_pH_Normal338, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal338 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal338->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah338, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang338 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang338->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal338, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal338 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal338->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang338, EC_Normal);
FuzzyRuleConsequent *Ganti338 = new FuzzyRuleConsequent();
Ganti338->addOutput(Ganti);
FuzzyRule *fuzzyRule338 = new FuzzyRule(338, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal338, Ganti338);
fuzzy->addFuzzyRule(fuzzyRule338);

// Rule 339 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal339 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal339->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah339 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah339->joinWithAND(DO_Normal_pH_Normal339, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal339 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal339->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah339, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang339 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang339->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal339, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi339 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi339->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang339, EC_Tinggi);
FuzzyRuleConsequent *Ganti339 = new FuzzyRuleConsequent();
Ganti339->addOutput(Ganti);
FuzzyRule *fuzzyRule339 = new FuzzyRule(339, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi339, Ganti339);
fuzzy->addFuzzyRule(fuzzyRule339);

// Rule 340 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal340 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal340->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah340 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah340->joinWithAND(DO_Normal_pH_Normal340, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal340 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal340->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah340, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam340 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam340->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal340, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah340 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah340->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam340, EC_Rendah);
FuzzyRuleConsequent *Ganti340 = new FuzzyRuleConsequent();
Ganti340->addOutput(Ganti);
FuzzyRule *fuzzyRule340 = new FuzzyRule(340, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah340, Ganti340);
fuzzy->addFuzzyRule(fuzzyRule340);

// Rule 341 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal341 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal341->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah341 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah341->joinWithAND(DO_Normal_pH_Normal341, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal341 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal341->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah341, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam341 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam341->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal341, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal341 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal341->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam341, EC_Normal);
FuzzyRuleConsequent *Ganti341 = new FuzzyRuleConsequent();
Ganti341->addOutput(Ganti);
FuzzyRule *fuzzyRule341 = new FuzzyRule(341, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal341, Ganti341);
fuzzy->addFuzzyRule(fuzzyRule341);

// Rule 342 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal342 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal342->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah342 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah342->joinWithAND(DO_Normal_pH_Normal342, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal342 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal342->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah342, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam342 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam342->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal342, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi342 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi342->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam342, EC_Tinggi);
FuzzyRuleConsequent *Ganti342 = new FuzzyRuleConsequent();
Ganti342->addOutput(Ganti);
FuzzyRule *fuzzyRule342 = new FuzzyRule(342, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi342, Ganti342);
fuzzy->addFuzzyRule(fuzzyRule342);

// Rule 343 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal343 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal343->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah343 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah343->joinWithAND(DO_Normal_pH_Normal343, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak343 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak343->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah343, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal343 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal343->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak343, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah343 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah343->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal343, EC_Rendah);
FuzzyRuleConsequent *Ganti343 = new FuzzyRuleConsequent();
Ganti343->addOutput(Ganti);
FuzzyRule *fuzzyRule343 = new FuzzyRule(343, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah343, Ganti343);
fuzzy->addFuzzyRule(fuzzyRule343);

// Rule 344 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal344 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal344->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah344 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah344->joinWithAND(DO_Normal_pH_Normal344, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak344 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak344->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah344, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal344 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal344->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak344, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal344 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal344->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal344, EC_Normal);
FuzzyRuleConsequent *Ganti344 = new FuzzyRuleConsequent();
Ganti344->addOutput(Ganti);
FuzzyRule *fuzzyRule344 = new FuzzyRule(344, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal344, Ganti344);
fuzzy->addFuzzyRule(fuzzyRule344);

// Rule 345 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal345 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal345->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah345 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah345->joinWithAND(DO_Normal_pH_Normal345, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak345 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak345->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah345, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal345 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal345->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak345, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi345 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi345->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal345, EC_Tinggi);
FuzzyRuleConsequent *Ganti345 = new FuzzyRuleConsequent();
Ganti345->addOutput(Ganti);
FuzzyRule *fuzzyRule345 = new FuzzyRule(345, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi345, Ganti345);
fuzzy->addFuzzyRule(fuzzyRule345);

// Rule 346 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal346 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal346->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah346 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah346->joinWithAND(DO_Normal_pH_Normal346, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak346 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak346->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah346, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang346 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang346->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak346, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah346 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah346->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang346, EC_Rendah);
FuzzyRuleConsequent *Ganti346 = new FuzzyRuleConsequent();
Ganti346->addOutput(Ganti);
FuzzyRule *fuzzyRule346 = new FuzzyRule(346, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah346, Ganti346);
fuzzy->addFuzzyRule(fuzzyRule346);

// Rule 347 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal347 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal347->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah347 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah347->joinWithAND(DO_Normal_pH_Normal347, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak347 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak347->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah347, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang347 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang347->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak347, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal347 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal347->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang347, EC_Normal);
FuzzyRuleConsequent *Ganti347 = new FuzzyRuleConsequent();
Ganti347->addOutput(Ganti);
FuzzyRule *fuzzyRule347 = new FuzzyRule(347, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal347, Ganti347);
fuzzy->addFuzzyRule(fuzzyRule347);

// Rule 348 (Jarak_Sedang, EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal348 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal348->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah348 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah348->joinWithAND(DO_Normal_pH_Normal348, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak348 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak348->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah348, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang348 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang348->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak348, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi348 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi348->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang348, EC_Tinggi);
FuzzyRuleConsequent *Ganti348 = new FuzzyRuleConsequent();
Ganti348->addOutput(Ganti);
FuzzyRule *fuzzyRule348 = new FuzzyRule(348, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi348, Ganti348);
fuzzy->addFuzzyRule(fuzzyRule348);

// Rule 349 (Jarak_Dalam, EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal349 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal349->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah349 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah349->joinWithAND(DO_Normal_pH_Normal349, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak349 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak349->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah349, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam349 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam349->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak349, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah349 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah349->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam349, EC_Rendah);
FuzzyRuleConsequent *Ganti349 = new FuzzyRuleConsequent();
Ganti349->addOutput(Ganti);
FuzzyRule *fuzzyRule349 = new FuzzyRule(349, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah349, Ganti349);
fuzzy->addFuzzyRule(fuzzyRule349);

// Rule 350 (EC_Normal, Jarak_Dalam)
FuzzyRuleAntecedent *DO_Normal_pH_Normal350 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal350->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah350 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah350->joinWithAND(DO_Normal_pH_Normal350, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak350 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak350->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah350, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam350 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam350->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak350, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal350 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal350->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam350, EC_Normal);
FuzzyRuleConsequent *Ganti350 = new FuzzyRuleConsequent();
Ganti350->addOutput(Ganti);
FuzzyRule *fuzzyRule350 = new FuzzyRule(350, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal350, Ganti350);
fuzzy->addFuzzyRule(fuzzyRule350);

// Rule 351 (EC_Tinggi, Jarak_Dalam)
FuzzyRuleAntecedent *DO_Normal_pH_Normal351 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal351->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah351 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah351->joinWithAND(DO_Normal_pH_Normal351, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak351 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak351->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah351, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam351 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam351->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak351, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi351 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi351->joinWithAND(DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam351, EC_Tinggi);
FuzzyRuleConsequent *Ganti351 = new FuzzyRuleConsequent();
Ganti351->addOutput(Ganti);
FuzzyRule *fuzzyRule351 = new FuzzyRule(351, DO_Normal_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi351, Ganti351);
fuzzy->addFuzzyRule(fuzzyRule351);

// Rule 352 (EC_Rendah, Jarak_Dangkal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal352 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal352->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal352 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal352->joinWithAND(DO_Normal_pH_Normal352, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah352 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah352->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal352, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal352 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal352->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah352, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah352 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah352->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal352, EC_Rendah);
FuzzyRuleConsequent *Ganti352 = new FuzzyRuleConsequent();
Ganti352->addOutput(Ganti);
FuzzyRule *fuzzyRule352 = new FuzzyRule(352, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah352, Ganti352);
fuzzy->addFuzzyRule(fuzzyRule352);

// Rule 353 (EC_Normal, Jarak_Dangkal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal353 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal353->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal353 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal353->joinWithAND(DO_Normal_pH_Normal353, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah353 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah353->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal353, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal353 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal353->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah353, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal353 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal353->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal353, EC_Normal);
FuzzyRuleConsequent *Ganti353 = new FuzzyRuleConsequent();
Ganti353->addOutput(Ganti);
FuzzyRule *fuzzyRule353 = new FuzzyRule(353, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal353, Ganti353);
fuzzy->addFuzzyRule(fuzzyRule353);

// Rule 354 (EC_Tinggi, Jarak_Dangkal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal354 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal354->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal354 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal354->joinWithAND(DO_Normal_pH_Normal354, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah354 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah354->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal354, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal354 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal354->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah354, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi354 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi354->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal354, EC_Tinggi);
FuzzyRuleConsequent *Ganti354 = new FuzzyRuleConsequent();
Ganti354->addOutput(Ganti);
FuzzyRule *fuzzyRule354 = new FuzzyRule(354, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi354, Ganti354);
fuzzy->addFuzzyRule(fuzzyRule354);

// Rule 355 (EC_Rendah, Jarak_Sedang)
FuzzyRuleAntecedent *DO_Normal_pH_Normal355 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal355->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal355 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal355->joinWithAND(DO_Normal_pH_Normal355, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah355 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah355->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal355, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang355 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang355->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah355, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah355 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah355->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang355, EC_Rendah);
FuzzyRuleConsequent *Aman355 = new FuzzyRuleConsequent();
Aman355->addOutput(Aman);
FuzzyRule *fuzzyRule355 = new FuzzyRule(355, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah355, Aman355);
fuzzy->addFuzzyRule(fuzzyRule355);

// Rule 356 (Jarak_Sedang, EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal356 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal356->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal356 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal356->joinWithAND(DO_Normal_pH_Normal356, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah356 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah356->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal356, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang356 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang356->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah356, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal356 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal356->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang356, EC_Normal);
FuzzyRuleConsequent *Aman356 = new FuzzyRuleConsequent();
Aman356->addOutput(Aman);
FuzzyRule *fuzzyRule356 = new FuzzyRule(356, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal356, Aman356);
fuzzy->addFuzzyRule(fuzzyRule356);

// Rule 357 (Jarak_Sedang, EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal357 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal357->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal357 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal357->joinWithAND(DO_Normal_pH_Normal357, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah357 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah357->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal357, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang357 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang357->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah357, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi357 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi357->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang357, EC_Tinggi);
FuzzyRuleConsequent *Ganti357 = new FuzzyRuleConsequent();
Ganti357->addOutput(Ganti);
FuzzyRule *fuzzyRule357 = new FuzzyRule(357, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi357, Ganti357);
fuzzy->addFuzzyRule(fuzzyRule357);

// Rule 358 (Jarak_Dalam, EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal358 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal358->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal358 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal358->joinWithAND(DO_Normal_pH_Normal358, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah358 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah358->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal358, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam358 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam358->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah358, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah358 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah358->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam358, EC_Rendah);
FuzzyRuleConsequent *Aman358 = new FuzzyRuleConsequent();
Aman358->addOutput(Ganti);
FuzzyRule *fuzzyRule358 = new FuzzyRule(358, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah358, Aman358);
fuzzy->addFuzzyRule(fuzzyRule358);

// Rule 359 (Jarak_Dalam, EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal359 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal359->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal359 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal359->joinWithAND(DO_Normal_pH_Normal359, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah359 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah359->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal359, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam359 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam359->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah359, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal359 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal359->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam359, EC_Normal);
FuzzyRuleConsequent *Aman359 = new FuzzyRuleConsequent();
Aman359->addOutput(Aman);
FuzzyRule *fuzzyRule359 = new FuzzyRule(359, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal359, Aman359);
fuzzy->addFuzzyRule(fuzzyRule359);

// Rule 360 (Jarak_Dalam, EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal360 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal360->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal360 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal360->joinWithAND(DO_Normal_pH_Normal360, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah360 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah360->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal360, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam360 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam360->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah360, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi360 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi360->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam360, EC_Tinggi);
FuzzyRuleConsequent *Ganti360 = new FuzzyRuleConsequent();
Ganti360->addOutput(Ganti);
FuzzyRule *fuzzyRule360 = new FuzzyRule(360, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi360, Ganti360);
fuzzy->addFuzzyRule(fuzzyRule360);

// Rule 361 (Jarak_Dangkal, EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal361 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal361->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal361 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal361->joinWithAND(DO_Normal_pH_Normal361, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal361 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal361->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal361, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal361 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal361->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal361, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah361 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah361->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal361, EC_Rendah);
FuzzyRuleConsequent *Ganti361 = new FuzzyRuleConsequent();
Ganti361->addOutput(Ganti);
FuzzyRule *fuzzyRule361 = new FuzzyRule(361, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah361, Ganti361);
fuzzy->addFuzzyRule(fuzzyRule361);

// Rule 362 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal362 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal362->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal362 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal362->joinWithAND(DO_Normal_pH_Normal362, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal362 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal362->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal362, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal362 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal362->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal362, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal362 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal362->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal362, EC_Normal);
FuzzyRuleConsequent *Ganti362 = new FuzzyRuleConsequent();
Ganti362->addOutput(Ganti);
FuzzyRule *fuzzyRule362 = new FuzzyRule(362, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal362, Ganti362);
fuzzy->addFuzzyRule(fuzzyRule362);

// Rule 363 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal363 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal363->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal363 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal363->joinWithAND(DO_Normal_pH_Normal363, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal363 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal363->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal363, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal363 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal363->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal363, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi363 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi363->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal363, EC_Tinggi);
FuzzyRuleConsequent *Ganti363 = new FuzzyRuleConsequent();
Ganti363->addOutput(Ganti);
FuzzyRule *fuzzyRule363 = new FuzzyRule(363, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi363, Ganti363);
fuzzy->addFuzzyRule(fuzzyRule363);

// Rule 364 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal364 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal364->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal364 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal364->joinWithAND(DO_Normal_pH_Normal364, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal364 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal364->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal364, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang364 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang364->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal364, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah364 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah364->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang364, EC_Rendah);
FuzzyRuleConsequent *Aman364 = new FuzzyRuleConsequent();
Aman364->addOutput(Aman);
FuzzyRule *fuzzyRule364 = new FuzzyRule(364, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah364, Aman364);
fuzzy->addFuzzyRule(fuzzyRule364);

// Rule 365 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal365 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal365->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal365 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal365->joinWithAND(DO_Normal_pH_Normal365, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal365 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal365->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal365, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang365 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang365->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal365, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal365 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal365->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang365, EC_Normal);
FuzzyRuleConsequent *Aman365 = new FuzzyRuleConsequent();
Aman365->addOutput(Aman);
FuzzyRule *fuzzyRule365 = new FuzzyRule(365, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal365, Aman365);
fuzzy->addFuzzyRule(fuzzyRule365);


// Rule 366 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal366 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal366->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal366 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal366->joinWithAND(DO_Normal_pH_Normal366, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal366 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal366->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal366, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang366 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang366->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal366, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi366 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi366->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang366, EC_Tinggi);
FuzzyRuleConsequent *Ganti366 = new FuzzyRuleConsequent();
Ganti366->addOutput(Ganti);
FuzzyRule *fuzzyRule366 = new FuzzyRule(366, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi366, Ganti366);
fuzzy->addFuzzyRule(fuzzyRule366);

// Rule 367 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal367 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal367->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal367 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal367->joinWithAND(DO_Normal_pH_Normal367, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal367 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal367->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal367, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam367 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam367->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal367, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah367 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah367->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam367, EC_Rendah);
FuzzyRuleConsequent *Aman367 = new FuzzyRuleConsequent();
Aman367->addOutput(Aman);
FuzzyRule *fuzzyRule367 = new FuzzyRule(367, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah367, Aman367);
fuzzy->addFuzzyRule(fuzzyRule367);

// Rule 368 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal368 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal368->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal368 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal368->joinWithAND(DO_Normal_pH_Normal368, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal368 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal368->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal368, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam368 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam368->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal368, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal368 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal368->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam368, EC_Normal);
FuzzyRuleConsequent *Aman368 = new FuzzyRuleConsequent();
Aman368->addOutput(Aman);
FuzzyRule *fuzzyRule368 = new FuzzyRule(368, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal368, Aman368);
fuzzy->addFuzzyRule(fuzzyRule368);

// Rule 369 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal369 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal369->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal369 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal369->joinWithAND(DO_Normal_pH_Normal369, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal369 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal369->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal369, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam369 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam369->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal369, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi369 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi369->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam369, EC_Tinggi);
FuzzyRuleConsequent *Ganti369 = new FuzzyRuleConsequent();
Ganti369->addOutput(Ganti);
FuzzyRule *fuzzyRule369 = new FuzzyRule(369, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi369, Ganti369);
fuzzy->addFuzzyRule(fuzzyRule369);


// Rule 370 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal370 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal370->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal370 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal370->joinWithAND(DO_Normal_pH_Normal370, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak370 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak370->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal370, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal370 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal370->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak370, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah370 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah370->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal370, EC_Rendah);
FuzzyRuleConsequent *Ganti370 = new FuzzyRuleConsequent();
Ganti370->addOutput(Ganti);
FuzzyRule *fuzzyRule370 = new FuzzyRule(370, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah370, Ganti370);
fuzzy->addFuzzyRule(fuzzyRule370);

// Rule 371 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal371 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal371->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal371 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal371->joinWithAND(DO_Normal_pH_Normal371, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak371 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak371->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal371, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal371 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal371->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak371, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal371 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal371->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal371, EC_Normal);
FuzzyRuleConsequent *Ganti371 = new FuzzyRuleConsequent();
Ganti371->addOutput(Ganti);
FuzzyRule *fuzzyRule371 = new FuzzyRule(371, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal371, Ganti371);
fuzzy->addFuzzyRule(fuzzyRule371);

// Rule 372 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal372 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal372->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal372 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal372->joinWithAND(DO_Normal_pH_Normal372, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak372 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak372->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal372, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal372 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal372->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak372, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi372 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi372->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal372, EC_Tinggi);
FuzzyRuleConsequent *Ganti372 = new FuzzyRuleConsequent();
Ganti372->addOutput(Ganti);
FuzzyRule *fuzzyRule372 = new FuzzyRule(372, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi372, Ganti372);
fuzzy->addFuzzyRule(fuzzyRule372);

// Rule 373 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal373 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal373->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal373 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal373->joinWithAND(DO_Normal_pH_Normal373, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak373 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak373->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal373, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang373 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang373->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak373, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah373 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah373->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang373, EC_Rendah);
FuzzyRuleConsequent *Ganti373 = new FuzzyRuleConsequent();
Ganti373->addOutput(Ganti);
FuzzyRule *fuzzyRule373 = new FuzzyRule(373, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah373, Ganti373);
fuzzy->addFuzzyRule(fuzzyRule373);

// Rule 374 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal374 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal374->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal374 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal374->joinWithAND(DO_Normal_pH_Normal374, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak374 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak374->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal374, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang374 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang374->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak374, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal374 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal374->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang374, EC_Normal);
FuzzyRuleConsequent *Ganti374 = new FuzzyRuleConsequent();
Ganti374->addOutput(Ganti);
FuzzyRule *fuzzyRule374 = new FuzzyRule(374, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal374, Ganti374);
fuzzy->addFuzzyRule(fuzzyRule374);

// Rule 375 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal375 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal375->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal375 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal375->joinWithAND(DO_Normal_pH_Normal375, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak375 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak375->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal375, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang375 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang375->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak375, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi375 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi375->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang375, EC_Tinggi);
FuzzyRuleConsequent *Ganti375 = new FuzzyRuleConsequent();
Ganti375->addOutput(Ganti);
FuzzyRule *fuzzyRule375 = new FuzzyRule(375, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi375, Ganti375);
fuzzy->addFuzzyRule(fuzzyRule375);

// Rule 376 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal376 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal376->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal376 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal376->joinWithAND(DO_Normal_pH_Normal376, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak376 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak376->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal376, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam376 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam376->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak376, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah376 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah376->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam376, EC_Rendah);
FuzzyRuleConsequent *Ganti376 = new FuzzyRuleConsequent();
Ganti376->addOutput(Ganti);
FuzzyRule *fuzzyRule376 = new FuzzyRule(376, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah376, Ganti376);
fuzzy->addFuzzyRule(fuzzyRule376);

// Rule 377 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal377 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal377->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal377 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal377->joinWithAND(DO_Normal_pH_Normal377, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak377 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak377->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal377, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam377 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam377->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak377, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal377 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal377->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam377, EC_Normal);
FuzzyRuleConsequent *Ganti377 = new FuzzyRuleConsequent();
Ganti377->addOutput(Ganti);
FuzzyRule *fuzzyRule377 = new FuzzyRule(377, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal377, Ganti377);
fuzzy->addFuzzyRule(fuzzyRule377);

// Rule 378 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal378 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal378->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal378 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal378->joinWithAND(DO_Normal_pH_Normal378, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak378 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak378->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal378, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam378 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam378->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak378, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi378 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi378->joinWithAND(DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam378, EC_Tinggi);
FuzzyRuleConsequent *Ganti378 = new FuzzyRuleConsequent();
Ganti378->addOutput(Ganti);
FuzzyRule *fuzzyRule378 = new FuzzyRule(378, DO_Normal_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi378, Ganti378);
fuzzy->addFuzzyRule(fuzzyRule378);

// Rule 379 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal379 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal379->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak379 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak379->joinWithAND(DO_Normal_pH_Normal379, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah379 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah379->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak379, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal379 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal379->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah379, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah379 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah379->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal379, EC_Rendah);
FuzzyRuleConsequent *Ganti379 = new FuzzyRuleConsequent();
Ganti379->addOutput(Ganti);
FuzzyRule *fuzzyRule379 = new FuzzyRule(379, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah379, Ganti379);
fuzzy->addFuzzyRule(fuzzyRule379);

// Rule 380 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal380 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal380->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak380 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak380->joinWithAND(DO_Normal_pH_Normal380, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah380 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah380->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak380, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal380 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal380->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah380, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal380 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal380->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal380, EC_Normal);
FuzzyRuleConsequent *Ganti380 = new FuzzyRuleConsequent();
Ganti380->addOutput(Ganti);
FuzzyRule *fuzzyRule380 = new FuzzyRule(380, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal380, Ganti380);
fuzzy->addFuzzyRule(fuzzyRule380);

// Rule 381 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal381 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal381->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak381 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak381->joinWithAND(DO_Normal_pH_Normal381, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah381 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah381->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak381, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal381 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal381->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah381, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi381 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi381->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal381, EC_Tinggi);
FuzzyRuleConsequent *Ganti381 = new FuzzyRuleConsequent();
Ganti381->addOutput(Ganti);
FuzzyRule *fuzzyRule381 = new FuzzyRule(381, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi381, Ganti381);
fuzzy->addFuzzyRule(fuzzyRule381);

// Rule 382 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal382 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal382->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak382 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak382->joinWithAND(DO_Normal_pH_Normal382, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah382 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah382->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak382, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang382 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang382->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah382, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah382 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah382->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang382, EC_Rendah);
FuzzyRuleConsequent *Ganti382 = new FuzzyRuleConsequent();
Ganti382->addOutput(Ganti);
FuzzyRule *fuzzyRule382 = new FuzzyRule(382, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah382, Ganti382);
fuzzy->addFuzzyRule(fuzzyRule382);

// Rule 383 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal383 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal383->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak383 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak383->joinWithAND(DO_Normal_pH_Normal383, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah383 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah383->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak383, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang383 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang383->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah383, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal383 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal383->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang383, EC_Normal);
FuzzyRuleConsequent *Ganti383 = new FuzzyRuleConsequent();
Ganti383->addOutput(Ganti);
FuzzyRule *fuzzyRule383 = new FuzzyRule(383, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal383, Ganti383);
fuzzy->addFuzzyRule(fuzzyRule383);

// Rule 384 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal384 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal384->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak384 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak384->joinWithAND(DO_Normal_pH_Normal384, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah384 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah384->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak384, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang384 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang384->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah384, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi384 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi384->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang384, EC_Tinggi);
FuzzyRuleConsequent *Ganti384 = new FuzzyRuleConsequent();
Ganti384->addOutput(Ganti);
FuzzyRule *fuzzyRule384 = new FuzzyRule(384, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi384, Ganti384);
fuzzy->addFuzzyRule(fuzzyRule384);

// Rule 385 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal385 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal385->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak385 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak385->joinWithAND(DO_Normal_pH_Normal385, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah385 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah385->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak385, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam385 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam385->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah385, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah385 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah385->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam385, EC_Rendah);
FuzzyRuleConsequent *Ganti385 = new FuzzyRuleConsequent();
Ganti385->addOutput(Ganti);
FuzzyRule *fuzzyRule385 = new FuzzyRule(385, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah385, Ganti385);
fuzzy->addFuzzyRule(fuzzyRule385);

// Rule 386 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal386 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal386->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak386 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak386->joinWithAND(DO_Normal_pH_Normal386, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah386 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah386->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak386, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam386 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam386->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah386, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal386 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal386->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam386, EC_Normal);
FuzzyRuleConsequent *Ganti386 = new FuzzyRuleConsequent();
Ganti386->addOutput(Ganti);
FuzzyRule *fuzzyRule386 = new FuzzyRule(386, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal386, Ganti386);
fuzzy->addFuzzyRule(fuzzyRule386);

// Rule 387 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal387 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal387->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak387 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak387->joinWithAND(DO_Normal_pH_Normal387, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah387 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah387->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak387, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam387 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam387->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah387, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi387 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi387->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam387, EC_Tinggi);
FuzzyRuleConsequent *Ganti387 = new FuzzyRuleConsequent();
Ganti387->addOutput(Ganti);
FuzzyRule *fuzzyRule387 = new FuzzyRule(387, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi387, Ganti387);
fuzzy->addFuzzyRule(fuzzyRule387);

// Rule 388 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal388 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal388->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak388 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak388->joinWithAND(DO_Normal_pH_Normal388, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal388 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal388->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak388, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal388 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal388->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal388, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah388 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah388->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal388, EC_Rendah);
FuzzyRuleConsequent *Ganti388 = new FuzzyRuleConsequent();
Ganti388->addOutput(Ganti);
FuzzyRule *fuzzyRule388 = new FuzzyRule(388, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah388, Ganti388);
fuzzy->addFuzzyRule(fuzzyRule388);

// Rule 389 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal389 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal389->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak389 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak389->joinWithAND(DO_Normal_pH_Normal389, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal389 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal389->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak389, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal389 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal389->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal389, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal389 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal389->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal389, EC_Normal);
FuzzyRuleConsequent *Ganti389 = new FuzzyRuleConsequent();
Ganti389->addOutput(Ganti);
FuzzyRule *fuzzyRule389 = new FuzzyRule(389, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal389, Ganti389);
fuzzy->addFuzzyRule(fuzzyRule389);

// Rule 390 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal390 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal390->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak390 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak390->joinWithAND(DO_Normal_pH_Normal390, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal390 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal390->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak390, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal390 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal390->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal390, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi390 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi390->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal390, EC_Tinggi);
FuzzyRuleConsequent *Ganti390 = new FuzzyRuleConsequent();
Ganti390->addOutput(Ganti);
FuzzyRule *fuzzyRule390 = new FuzzyRule(390, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi390, Ganti390);
fuzzy->addFuzzyRule(fuzzyRule390);

// Rule 391 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal391 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal391->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak391 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak391->joinWithAND(DO_Normal_pH_Normal391, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal391 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal391->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak391, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang391 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang391->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal391, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah391 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah391->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang391, EC_Rendah);
FuzzyRuleConsequent *Ganti391 = new FuzzyRuleConsequent();
Ganti391->addOutput(Ganti);
FuzzyRule *fuzzyRule391 = new FuzzyRule(391, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah391, Ganti391);
fuzzy->addFuzzyRule(fuzzyRule391);

// Rule 392 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal392 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal392->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak392 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak392->joinWithAND(DO_Normal_pH_Normal392, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal392 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal392->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak392, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang392 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang392->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal392, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal392 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal392->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang392, EC_Normal);
FuzzyRuleConsequent *Ganti392 = new FuzzyRuleConsequent();
Ganti392->addOutput(Ganti);
FuzzyRule *fuzzyRule392 = new FuzzyRule(392, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal392, Ganti392);
fuzzy->addFuzzyRule(fuzzyRule392);

// Rule 393 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal393 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal393->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak393 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak393->joinWithAND(DO_Normal_pH_Normal393, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal393 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal393->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak393, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang393 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang393->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal393, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi393 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi393->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang393, EC_Tinggi);
FuzzyRuleConsequent *Ganti393 = new FuzzyRuleConsequent();
Ganti393->addOutput(Ganti);
FuzzyRule *fuzzyRule393 = new FuzzyRule(393, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi393, Ganti393);
fuzzy->addFuzzyRule(fuzzyRule393);

// Rule 394 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal394 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal394->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak394 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak394->joinWithAND(DO_Normal_pH_Normal394, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal394 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal394->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak394, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam394 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam394->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal394, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah394 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah394->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam394, EC_Rendah);
FuzzyRuleConsequent *Ganti394 = new FuzzyRuleConsequent();
Ganti394->addOutput(Ganti);
FuzzyRule *fuzzyRule394 = new FuzzyRule(394, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah394, Ganti394);
fuzzy->addFuzzyRule(fuzzyRule394);

// Rule 395 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal395 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal395->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak395 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak395->joinWithAND(DO_Normal_pH_Normal395, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal395 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal395->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak395, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam395 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam395->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal395, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal395 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal395->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam395, EC_Normal);
FuzzyRuleConsequent *Ganti395 = new FuzzyRuleConsequent();
Ganti395->addOutput(Ganti);
FuzzyRule *fuzzyRule395 = new FuzzyRule(395, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal395, Ganti395);
fuzzy->addFuzzyRule(fuzzyRule395);

// Rule 396 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal396 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal396->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak396 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak396->joinWithAND(DO_Normal_pH_Normal396, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal396 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal396->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak396, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam396 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam396->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal396, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi396 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi396->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam396, EC_Tinggi);
FuzzyRuleConsequent *Ganti396 = new FuzzyRuleConsequent();
Ganti396->addOutput(Ganti);
FuzzyRule *fuzzyRule396 = new FuzzyRule(396, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi396, Ganti396);
fuzzy->addFuzzyRule(fuzzyRule396);

// Rule 397 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal397 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal397->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak397 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak397->joinWithAND(DO_Normal_pH_Normal397, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak397 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak397->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak397, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal397 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal397->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak397, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah397 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah397->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal397, EC_Rendah);
FuzzyRuleConsequent *Ganti397 = new FuzzyRuleConsequent();
Ganti397->addOutput(Ganti);
FuzzyRule *fuzzyRule397 = new FuzzyRule(397, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah397, Ganti397);
fuzzy->addFuzzyRule(fuzzyRule397);

// Rule 398 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal398 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal398->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak398 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak398->joinWithAND(DO_Normal_pH_Normal398, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak398 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak398->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak398, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal398 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal398->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak398, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal398 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal398->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal398, EC_Normal);
FuzzyRuleConsequent *Ganti398 = new FuzzyRuleConsequent();
Ganti398->addOutput(Ganti);
FuzzyRule *fuzzyRule398 = new FuzzyRule(398, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal398, Ganti398);
fuzzy->addFuzzyRule(fuzzyRule398);

// Rule 399 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal399 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal399->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak399 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak399->joinWithAND(DO_Normal_pH_Normal399, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak399 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak399->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak399, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal399 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal399->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak399, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi399 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi399->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal399, EC_Tinggi);
FuzzyRuleConsequent *Ganti399 = new FuzzyRuleConsequent();
Ganti399->addOutput(Ganti);
FuzzyRule *fuzzyRule399 = new FuzzyRule(399, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi399, Ganti399);
fuzzy->addFuzzyRule(fuzzyRule399);

// Rule 400 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal400 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal400->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak400 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak400->joinWithAND(DO_Normal_pH_Normal400, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak400 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak400->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak400, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang400 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang400->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak400, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah400 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah400->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang400, EC_Rendah);
FuzzyRuleConsequent *Ganti400 = new FuzzyRuleConsequent();
Ganti400->addOutput(Ganti);
FuzzyRule *fuzzyRule400 = new FuzzyRule(400, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah400, Ganti400);
fuzzy->addFuzzyRule(fuzzyRule400);

// Rule 401 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal401 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal401->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak401 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak401->joinWithAND(DO_Normal_pH_Normal401, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak401 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak401->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak401, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang401 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang401->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak401, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal401 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal401->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang401, EC_Normal);
FuzzyRuleConsequent *Aman401 = new FuzzyRuleConsequent();
Aman401->addOutput(Aman);
FuzzyRule *fuzzyRule401 = new FuzzyRule(401, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal401, Aman401);
fuzzy->addFuzzyRule(fuzzyRule401);

// Rule 402 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal402 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal402->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak402 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak402->joinWithAND(DO_Normal_pH_Normal402, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak402 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak402->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak402, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang402 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang402->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak402, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi402 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi402->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang402, EC_Tinggi);
FuzzyRuleConsequent *Ganti402 = new FuzzyRuleConsequent();
Ganti402->addOutput(Ganti);
FuzzyRule *fuzzyRule402 = new FuzzyRule(402, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi402, Ganti402);
fuzzy->addFuzzyRule(fuzzyRule402);

// Rule 403 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Normal403 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal403->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak403 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak403->joinWithAND(DO_Normal_pH_Normal403, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak403 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak403->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak403, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam403 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam403->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak403, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah403 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah403->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam403, EC_Rendah);
FuzzyRuleConsequent *Ganti403 = new FuzzyRuleConsequent();
Ganti403->addOutput(Ganti);
FuzzyRule *fuzzyRule403 = new FuzzyRule(403, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah403, Ganti403);
fuzzy->addFuzzyRule(fuzzyRule403);

// Rule 404 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Normal404 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal404->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak404 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak404->joinWithAND(DO_Normal_pH_Normal404, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak404 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak404->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak404, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam404 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam404->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak404, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal404 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal404->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam404, EC_Normal);
FuzzyRuleConsequent *Aman404 = new FuzzyRuleConsequent();
Aman404->addOutput(Aman);
FuzzyRule *fuzzyRule404 = new FuzzyRule(404, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal404, Aman404);
fuzzy->addFuzzyRule(fuzzyRule404);

// Rule 405 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Normal405 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal405->joinWithAND(DO_Normal, pH_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak405 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak405->joinWithAND(DO_Normal_pH_Normal405, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak405 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak405->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak405, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam405 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam405->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak405, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi405 = new FuzzyRuleAntecedent();
DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi405->joinWithAND(DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam405, EC_Tinggi);
FuzzyRuleConsequent *Ganti405 = new FuzzyRuleConsequent();
Ganti405->addOutput(Ganti);
FuzzyRule *fuzzyRule405 = new FuzzyRule(405, DO_Normal_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi405, Ganti405);
fuzzy->addFuzzyRule(fuzzyRule405);

// Rule 406
FuzzyRuleAntecedent *DO_Normal_pH_Banyak406 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak406->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah406 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah406->joinWithAND(DO_Normal_pH_Banyak406, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah406 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah406->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah406, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal406 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal406->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah406, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah406 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah406->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal406, EC_Rendah);
FuzzyRuleConsequent *Ganti406 = new FuzzyRuleConsequent();
Ganti406->addOutput(Ganti);
FuzzyRule *fuzzyRule406 = new FuzzyRule(406, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah406, Ganti406);
fuzzy->addFuzzyRule(fuzzyRule406);

// Rule 407 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak407 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak407->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah407 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah407->joinWithAND(DO_Normal_pH_Banyak407, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah407 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah407->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah407, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal407 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal407->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah407, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal407 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal407->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal407, EC_Normal);
FuzzyRuleConsequent *Ganti407 = new FuzzyRuleConsequent();
Ganti407->addOutput(Ganti);
FuzzyRule *fuzzyRule407 = new FuzzyRule(407, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal407, Ganti407);
fuzzy->addFuzzyRule(fuzzyRule407);

// Rule 408 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak408 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak408->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah408 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah408->joinWithAND(DO_Normal_pH_Banyak408, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah408 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah408->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah408, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal408 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal408->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah408, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi408 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi408->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal408, EC_Tinggi);
FuzzyRuleConsequent *Ganti408 = new FuzzyRuleConsequent();
Ganti408->addOutput(Ganti);
FuzzyRule *fuzzyRule408 = new FuzzyRule(408, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi408, Ganti408);
fuzzy->addFuzzyRule(fuzzyRule408);

// Rule 409 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak409 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak409->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah409 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah409->joinWithAND(DO_Normal_pH_Banyak409, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah409 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah409->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah409, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang409 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang409->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah409, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah409 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah409->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang409, EC_Rendah);
FuzzyRuleConsequent *Ganti409 = new FuzzyRuleConsequent();
Ganti409->addOutput(Ganti);
FuzzyRule *fuzzyRule409 = new FuzzyRule(409, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah409, Ganti409);
fuzzy->addFuzzyRule(fuzzyRule409);

// Rule 410 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak410 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak410->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah410 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah410->joinWithAND(DO_Normal_pH_Banyak410, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah410 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah410->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah410, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang410 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang410->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah410, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal410 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal410->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang410, EC_Normal);
FuzzyRuleConsequent *Ganti410 = new FuzzyRuleConsequent();
Ganti410->addOutput(Ganti);
FuzzyRule *fuzzyRule410 = new FuzzyRule(410, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal410, Ganti410);
fuzzy->addFuzzyRule(fuzzyRule410);

// Rule 411 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak411 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak411->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah411 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah411->joinWithAND(DO_Normal_pH_Banyak411, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah411 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah411->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah411, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang411 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang411->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah411, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi411 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi411->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang411, EC_Tinggi);
FuzzyRuleConsequent *Ganti411 = new FuzzyRuleConsequent();
Ganti411->addOutput(Ganti);
FuzzyRule *fuzzyRule411 = new FuzzyRule(411, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi411, Ganti411);
fuzzy->addFuzzyRule(fuzzyRule411);

// Rule 412 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak412 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak412->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah412 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah412->joinWithAND(DO_Normal_pH_Banyak412, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah412 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah412->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah412, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam412 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam412->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah412, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah412 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah412->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam412, EC_Rendah);
FuzzyRuleConsequent *Ganti412 = new FuzzyRuleConsequent();
Ganti412->addOutput(Ganti);
FuzzyRule *fuzzyRule412 = new FuzzyRule(412, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah412, Ganti412);
fuzzy->addFuzzyRule(fuzzyRule412);

// Rule 413 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak413 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak413->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah413 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah413->joinWithAND(DO_Normal_pH_Banyak413, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah413 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah413->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah413, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam413 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam413->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah413, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal413 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal413->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam413, EC_Normal);
FuzzyRuleConsequent *Ganti413 = new FuzzyRuleConsequent();
Ganti413->addOutput(Ganti);
FuzzyRule *fuzzyRule413 = new FuzzyRule(413, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal413, Ganti413);
fuzzy->addFuzzyRule(fuzzyRule413);

// Rule 414 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak414 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak414->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah414 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah414->joinWithAND(DO_Normal_pH_Banyak414, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah414 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah414->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah414, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam414 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam414->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah414, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi414 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi414->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam414, EC_Tinggi);
FuzzyRuleConsequent *Ganti414 = new FuzzyRuleConsequent();
Ganti414->addOutput(Ganti);
FuzzyRule *fuzzyRule414 = new FuzzyRule(414, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi414, Ganti414);
fuzzy->addFuzzyRule(fuzzyRule414);

// Rule 415 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak415 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak415->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah415 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah415->joinWithAND(DO_Normal_pH_Banyak415, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal415 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal415->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah415, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal415 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal415->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal415, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah415 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah415->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal415, EC_Rendah);
FuzzyRuleConsequent *Ganti415 = new FuzzyRuleConsequent();
Ganti415->addOutput(Ganti);
FuzzyRule *fuzzyRule415 = new FuzzyRule(415, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah415, Ganti415);
fuzzy->addFuzzyRule(fuzzyRule415);

// Rule 416 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak416 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak416->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah416 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah416->joinWithAND(DO_Normal_pH_Banyak416, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal416 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal416->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah416, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal416 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal416->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal416, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal416 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal416->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal416, EC_Normal);
FuzzyRuleConsequent *Ganti416 = new FuzzyRuleConsequent();
Ganti416->addOutput(Ganti);
FuzzyRule *fuzzyRule416 = new FuzzyRule(416, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal416, Ganti416);
fuzzy->addFuzzyRule(fuzzyRule416);

// Rule 417 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak417 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak417->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah417 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah417->joinWithAND(DO_Normal_pH_Banyak417, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal417 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal417->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah417, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal417 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal417->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal417, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi417 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi417->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal417, EC_Tinggi);
FuzzyRuleConsequent *Ganti417 = new FuzzyRuleConsequent();
Ganti417->addOutput(Ganti);
FuzzyRule *fuzzyRule417 = new FuzzyRule(417, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi417, Ganti417);
fuzzy->addFuzzyRule(fuzzyRule417);

// Rule 418 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak418 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak418->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah418 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah418->joinWithAND(DO_Normal_pH_Banyak418, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal418 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal418->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah418, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang418 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang418->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal418, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah418 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah418->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang418, EC_Rendah);
FuzzyRuleConsequent *Ganti418 = new FuzzyRuleConsequent();
Ganti418->addOutput(Ganti);
FuzzyRule *fuzzyRule418 = new FuzzyRule(418, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah418, Ganti418);
fuzzy->addFuzzyRule(fuzzyRule418);

// Rule 419 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak419 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak419->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah419 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah419->joinWithAND(DO_Normal_pH_Banyak419, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal419 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal419->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah419, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang419 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang419->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal419, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal419 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal419->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang419, EC_Normal);
FuzzyRuleConsequent *Ganti419 = new FuzzyRuleConsequent();
Ganti419->addOutput(Ganti);
FuzzyRule *fuzzyRule419 = new FuzzyRule(419, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal419, Ganti419);
fuzzy->addFuzzyRule(fuzzyRule419);

// Rule 420 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak420 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak420->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah420 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah420->joinWithAND(DO_Normal_pH_Banyak420, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal420 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal420->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah420, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang420 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang420->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal420, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi420 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi420->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang420, EC_Tinggi);
FuzzyRuleConsequent *Ganti420 = new FuzzyRuleConsequent();
Ganti420->addOutput(Ganti);
FuzzyRule *fuzzyRule420 = new FuzzyRule(420, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi420, Ganti420);
fuzzy->addFuzzyRule(fuzzyRule420);

// Rule 421 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak421 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak421->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah421 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah421->joinWithAND(DO_Normal_pH_Banyak421, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal421 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal421->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah421, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam421 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam421->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal421, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah421 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah421->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam421, EC_Rendah);
FuzzyRuleConsequent *Ganti421 = new FuzzyRuleConsequent();
Ganti421->addOutput(Ganti);
FuzzyRule *fuzzyRule421 = new FuzzyRule(421, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah421, Ganti421);
fuzzy->addFuzzyRule(fuzzyRule421);

// Rule 422 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak422 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak422->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah422 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah422->joinWithAND(DO_Normal_pH_Banyak422, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal422 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal422->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah422, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam422 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam422->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal422, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal422 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal422->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam422, EC_Normal);
FuzzyRuleConsequent *Ganti422 = new FuzzyRuleConsequent();
Ganti422->addOutput(Ganti);
FuzzyRule *fuzzyRule422 = new FuzzyRule(422, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal422, Ganti422);
fuzzy->addFuzzyRule(fuzzyRule422);

// Rule 423 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak423 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak423->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah423 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah423->joinWithAND(DO_Normal_pH_Banyak423, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal423 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal423->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah423, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam423 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam423->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal423, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi423 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi423->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam423, EC_Tinggi);
FuzzyRuleConsequent *Ganti423 = new FuzzyRuleConsequent();
Ganti423->addOutput(Ganti);
FuzzyRule *fuzzyRule423 = new FuzzyRule(423, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi423, Ganti423);
fuzzy->addFuzzyRule(fuzzyRule423);

// Rule 424 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak424 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak424->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah424 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah424->joinWithAND(DO_Normal_pH_Banyak424, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak424 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak424->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah424, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal424 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal424->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak424, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah424 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah424->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal424, EC_Rendah);
FuzzyRuleConsequent *Ganti424 = new FuzzyRuleConsequent();
Ganti424->addOutput(Ganti);
FuzzyRule *fuzzyRule424 = new FuzzyRule(424, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah424, Ganti424);
fuzzy->addFuzzyRule(fuzzyRule424);

// Rule 425 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak425 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak425->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah425 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah425->joinWithAND(DO_Normal_pH_Banyak425, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak425 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak425->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah425, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal425 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal425->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak425, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal425 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal425->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal425, EC_Normal);
FuzzyRuleConsequent *Ganti425 = new FuzzyRuleConsequent();
Ganti425->addOutput(Ganti);
FuzzyRule *fuzzyRule425 = new FuzzyRule(425, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal425, Ganti425);
fuzzy->addFuzzyRule(fuzzyRule425);

// Rule 426 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak426 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak426->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah426 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah426->joinWithAND(DO_Normal_pH_Banyak426, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak426 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak426->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah426, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal426 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal426->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak426, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi426 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi426->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal426, EC_Tinggi);
FuzzyRuleConsequent *Ganti426 = new FuzzyRuleConsequent();
Ganti426->addOutput(Ganti);
FuzzyRule *fuzzyRule426 = new FuzzyRule(426, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi426, Ganti426);
fuzzy->addFuzzyRule(fuzzyRule426);

// Rule 427 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak427 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak427->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah427 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah427->joinWithAND(DO_Normal_pH_Banyak427, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak427 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak427->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah427, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang427 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang427->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak427, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah427 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah427->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang427, EC_Rendah);
FuzzyRuleConsequent *Ganti427 = new FuzzyRuleConsequent();
Ganti427->addOutput(Ganti);
FuzzyRule *fuzzyRule427 = new FuzzyRule(427, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah427, Ganti427);
fuzzy->addFuzzyRule(fuzzyRule427);

// Rule 428 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak428 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak428->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah428 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah428->joinWithAND(DO_Normal_pH_Banyak428, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak428 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak428->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah428, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang428 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang428->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak428, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal428 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal428->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang428, EC_Normal);
FuzzyRuleConsequent *Ganti428 = new FuzzyRuleConsequent();
Ganti428->addOutput(Ganti);
FuzzyRule *fuzzyRule428 = new FuzzyRule(428, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal428, Ganti428);
fuzzy->addFuzzyRule(fuzzyRule428);

// Rule 429 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak429 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak429->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah429 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah429->joinWithAND(DO_Normal_pH_Banyak429, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak429 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak429->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah429, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang429 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang429->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak429, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi429 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi429->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang429, EC_Tinggi);
FuzzyRuleConsequent *Ganti429 = new FuzzyRuleConsequent();
Ganti429->addOutput(Ganti);
FuzzyRule *fuzzyRule429 = new FuzzyRule(429, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi429, Ganti429);
fuzzy->addFuzzyRule(fuzzyRule429);

// Rule 430 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak430 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak430->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah430 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah430->joinWithAND(DO_Normal_pH_Banyak430, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak430 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak430->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah430, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam430 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam430->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak430, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah430 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah430->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam430, EC_Rendah);
FuzzyRuleConsequent *Ganti430 = new FuzzyRuleConsequent();
Ganti430->addOutput(Ganti);
FuzzyRule *fuzzyRule430 = new FuzzyRule(430, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah430, Ganti430);
fuzzy->addFuzzyRule(fuzzyRule430);

// Rule 431 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak431 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak431->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah431 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah431->joinWithAND(DO_Normal_pH_Banyak431, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak431 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak431->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah431, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam431 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam431->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak431, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal431 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal431->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam431, EC_Normal);
FuzzyRuleConsequent *Ganti431 = new FuzzyRuleConsequent();
Ganti431->addOutput(Ganti);
FuzzyRule *fuzzyRule431 = new FuzzyRule(431, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal431, Ganti431);
fuzzy->addFuzzyRule(fuzzyRule431);

// Rule 432 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak432 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak432->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah432 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah432->joinWithAND(DO_Normal_pH_Banyak432, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak432 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak432->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah432, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam432 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam432->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak432, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi432 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi432->joinWithAND(DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam432, EC_Tinggi);
FuzzyRuleConsequent *Ganti432 = new FuzzyRuleConsequent();
Ganti432->addOutput(Ganti);
FuzzyRule *fuzzyRule432 = new FuzzyRule(432, DO_Normal_pH_Banyak_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi432, Ganti432);
fuzzy->addFuzzyRule(fuzzyRule432);

// Rule 433 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak433 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak433->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal433 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal433->joinWithAND(DO_Normal_pH_Banyak433, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah433 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah433->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal433, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal433 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal433->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah433, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah433 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah433->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal433, EC_Rendah);
FuzzyRuleConsequent *Ganti433 = new FuzzyRuleConsequent();
Ganti433->addOutput(Ganti);
FuzzyRule *fuzzyRule433 = new FuzzyRule(433, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah433, Ganti433);
fuzzy->addFuzzyRule(fuzzyRule433);

// Rule 434 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak434 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak434->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal434 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal434->joinWithAND(DO_Normal_pH_Banyak434, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah434 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah434->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal434, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal434 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal434->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah434, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal434 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal434->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal434, EC_Normal);
FuzzyRuleConsequent *Ganti434 = new FuzzyRuleConsequent();
Ganti434->addOutput(Ganti);
FuzzyRule *fuzzyRule434 = new FuzzyRule(434, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal434, Ganti434);
fuzzy->addFuzzyRule(fuzzyRule434);

// Rule 435 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak435 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak435->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal435 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal435->joinWithAND(DO_Normal_pH_Banyak435, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah435 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah435->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal435, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal435 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal435->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah435, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi435 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi435->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal435, EC_Tinggi);
FuzzyRuleConsequent *Ganti435 = new FuzzyRuleConsequent();
Ganti435->addOutput(Ganti);
FuzzyRule *fuzzyRule435 = new FuzzyRule(435, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi435, Ganti435);
fuzzy->addFuzzyRule(fuzzyRule435);

// Rule 436 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak436 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak436->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal436 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal436->joinWithAND(DO_Normal_pH_Banyak436, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah436 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah436->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal436, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang436 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang436->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah436, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah436 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah436->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang436, EC_Rendah);
FuzzyRuleConsequent *Ganti436 = new FuzzyRuleConsequent();
Ganti436->addOutput(Ganti);
FuzzyRule *fuzzyRule436 = new FuzzyRule(436, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah436, Ganti436);
fuzzy->addFuzzyRule(fuzzyRule436);

// Rule 437 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak437 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak437->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal437 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal437->joinWithAND(DO_Normal_pH_Banyak437, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah437 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah437->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal437, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang437 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang437->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah437, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal437 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal437->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang437, EC_Normal);
FuzzyRuleConsequent *Ganti437 = new FuzzyRuleConsequent();
Ganti437->addOutput(Ganti);
FuzzyRule *fuzzyRule437 = new FuzzyRule(437, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal437, Ganti437);
fuzzy->addFuzzyRule(fuzzyRule437);

// Rule 438 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak438 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak438->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal438 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal438->joinWithAND(DO_Normal_pH_Banyak438, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah438 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah438->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal438, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang438 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang438->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah438, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi438 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi438->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang438, EC_Tinggi);
FuzzyRuleConsequent *Ganti438 = new FuzzyRuleConsequent();
Ganti438->addOutput(Ganti);
FuzzyRule *fuzzyRule438 = new FuzzyRule(438, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi438, Ganti438);
fuzzy->addFuzzyRule(fuzzyRule438);

// Rule 439 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak439 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak439->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal439 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal439->joinWithAND(DO_Normal_pH_Banyak439, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah439 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah439->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal439, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam439 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam439->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah439, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah439 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah439->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam439, EC_Rendah);
FuzzyRuleConsequent *Ganti439 = new FuzzyRuleConsequent();
Ganti439->addOutput(Ganti);
FuzzyRule *fuzzyRule439 = new FuzzyRule(439, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah439, Ganti439);
fuzzy->addFuzzyRule(fuzzyRule439);

// Rule 440 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak440 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak440->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal440 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal440->joinWithAND(DO_Normal_pH_Banyak440, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah440 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah440->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal440, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam440 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam440->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah440, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal440 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal440->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam440, EC_Normal);
FuzzyRuleConsequent *Ganti440 = new FuzzyRuleConsequent();
Ganti440->addOutput(Ganti);
FuzzyRule *fuzzyRule440 = new FuzzyRule(440, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal440, Ganti440);
fuzzy->addFuzzyRule(fuzzyRule440);

// Rule 441 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak441 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak441->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal441 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal441->joinWithAND(DO_Normal_pH_Banyak441, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah441 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah441->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal441, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam441 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam441->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah441, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi441 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi441->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam441, EC_Tinggi);
FuzzyRuleConsequent *Ganti441 = new FuzzyRuleConsequent();
Ganti441->addOutput(Ganti);
FuzzyRule *fuzzyRule441 = new FuzzyRule(441, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi441, Ganti441);
fuzzy->addFuzzyRule(fuzzyRule441);

// Rule 442 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak442 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak442->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal442 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal442->joinWithAND(DO_Normal_pH_Banyak442, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal442 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal442->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal442, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal442 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal442->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal442, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah442 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah442->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal442, EC_Rendah);
FuzzyRuleConsequent *Ganti442 = new FuzzyRuleConsequent();
Ganti442->addOutput(Ganti);
FuzzyRule *fuzzyRule442 = new FuzzyRule(442, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah442, Ganti442);
fuzzy->addFuzzyRule(fuzzyRule442);

// Rule 443 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak443 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak443->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal443 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal443->joinWithAND(DO_Normal_pH_Banyak443, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal443 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal443->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal443, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal443 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal443->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal443, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal443 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal443->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal443, EC_Normal);
FuzzyRuleConsequent *Ganti443 = new FuzzyRuleConsequent();
Ganti443->addOutput(Ganti);
FuzzyRule *fuzzyRule443 = new FuzzyRule(443, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal443, Ganti443);
fuzzy->addFuzzyRule(fuzzyRule443);

// Rule 444 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak444 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak444->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal444 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal444->joinWithAND(DO_Normal_pH_Banyak444, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal444 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal444->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal444, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal444 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal444->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal444, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi444 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi444->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal444, EC_Tinggi);
FuzzyRuleConsequent *Ganti444 = new FuzzyRuleConsequent();
Ganti444->addOutput(Ganti);
FuzzyRule *fuzzyRule444 = new FuzzyRule(444, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi444, Ganti444);
fuzzy->addFuzzyRule(fuzzyRule444);

// Rule 445 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak445 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak445->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal445 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal445->joinWithAND(DO_Normal_pH_Banyak445, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal445 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal445->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal445, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang445 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang445->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal445, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah445 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah445->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang445, EC_Rendah);
FuzzyRuleConsequent *Ganti445 = new FuzzyRuleConsequent();
Ganti445->addOutput(Ganti);
FuzzyRule *fuzzyRule445 = new FuzzyRule(445, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah445, Ganti445);
fuzzy->addFuzzyRule(fuzzyRule445);

// Rule 446 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak446 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak446->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal446 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal446->joinWithAND(DO_Normal_pH_Banyak446, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal446 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal446->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal446, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang446 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang446->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal446, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal446 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal446->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang446, EC_Normal);
FuzzyRuleConsequent *Ganti446 = new FuzzyRuleConsequent();
Ganti446->addOutput(Ganti);
FuzzyRule *fuzzyRule446 = new FuzzyRule(446, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal446, Ganti446);
fuzzy->addFuzzyRule(fuzzyRule446);

// Rule 447 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak447 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak447->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal447 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal447->joinWithAND(DO_Normal_pH_Banyak447, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal447 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal447->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal447, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang447 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang447->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal447, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi447 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi447->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang447, EC_Tinggi);
FuzzyRuleConsequent *Ganti447 = new FuzzyRuleConsequent();
Ganti447->addOutput(Ganti);
FuzzyRule *fuzzyRule447 = new FuzzyRule(447, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi447, Ganti447);
fuzzy->addFuzzyRule(fuzzyRule447);

// Rule 448 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak448 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak448->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal448 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal448->joinWithAND(DO_Normal_pH_Banyak448, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal448 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal448->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal448, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam448 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam448->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal448, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah448 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah448->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam448, EC_Rendah);
FuzzyRuleConsequent *Ganti448 = new FuzzyRuleConsequent();
Ganti448->addOutput(Ganti);
FuzzyRule *fuzzyRule448 = new FuzzyRule(448, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah448, Ganti448);
fuzzy->addFuzzyRule(fuzzyRule448);

// Rule 449 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak449 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak449->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal449 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal449->joinWithAND(DO_Normal_pH_Banyak449, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal449 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal449->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal449, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam449 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam449->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal449, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal449 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal449->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam449, EC_Normal);
FuzzyRuleConsequent *Ganti449 = new FuzzyRuleConsequent();
Ganti449->addOutput(Ganti);
FuzzyRule *fuzzyRule449 = new FuzzyRule(449, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal449, Ganti449);
fuzzy->addFuzzyRule(fuzzyRule449);

// Rule 450 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak450 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak450->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal450 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal450->joinWithAND(DO_Normal_pH_Banyak450, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal450 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal450->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal450, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam450 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam450->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal450, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi450 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi450->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam450, EC_Tinggi);
FuzzyRuleConsequent *Ganti450 = new FuzzyRuleConsequent();
Ganti450->addOutput(Ganti);
FuzzyRule *fuzzyRule450 = new FuzzyRule(450, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi450, Ganti450);
fuzzy->addFuzzyRule(fuzzyRule450);

// Rule 451 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak451 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak451->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal451 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal451->joinWithAND(DO_Normal_pH_Banyak451, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak451 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak451->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal451, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal451 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal451->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak451, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah451 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah451->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal451, EC_Rendah);
FuzzyRuleConsequent *Ganti451 = new FuzzyRuleConsequent();
Ganti451->addOutput(Ganti);
FuzzyRule *fuzzyRule451 = new FuzzyRule(451, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah451, Ganti451);
fuzzy->addFuzzyRule(fuzzyRule451);

// Rule 452 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak452 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak452->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal452 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal452->joinWithAND(DO_Normal_pH_Banyak452, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak452 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak452->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal452, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal452 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal452->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak452, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal452 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal452->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal452, EC_Normal);
FuzzyRuleConsequent *Ganti452 = new FuzzyRuleConsequent();
Ganti452->addOutput(Ganti);
FuzzyRule *fuzzyRule452 = new FuzzyRule(452, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal452, Ganti452);
fuzzy->addFuzzyRule(fuzzyRule452);

// Rule 453 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak453 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak453->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal453 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal453->joinWithAND(DO_Normal_pH_Banyak453, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak453 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak453->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal453, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal453 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal453->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak453, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi453 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi453->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal453, EC_Tinggi);
FuzzyRuleConsequent *Ganti453 = new FuzzyRuleConsequent();
Ganti453->addOutput(Ganti);
FuzzyRule *fuzzyRule453 = new FuzzyRule(453, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi453, Ganti453);
fuzzy->addFuzzyRule(fuzzyRule453);

// Rule 454 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak454 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak454->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal454 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal454->joinWithAND(DO_Normal_pH_Banyak454, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak454 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak454->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal454, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang454 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang454->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak454, Jarak_Sedang); // Change here
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah454 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah454->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang454, EC_Rendah);
FuzzyRuleConsequent *Ganti454 = new FuzzyRuleConsequent();
Ganti454->addOutput(Ganti);
FuzzyRule *fuzzyRule454 = new FuzzyRule(454, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah454, Ganti454);
fuzzy->addFuzzyRule(fuzzyRule454);

// Rule 455 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak455 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak455->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal455 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal455->joinWithAND(DO_Normal_pH_Banyak455, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak455 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak455->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal455, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang455 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang455->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak455, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal455 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal455->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang455, EC_Normal); // Change here
FuzzyRuleConsequent *Ganti455 = new FuzzyRuleConsequent();
Ganti455->addOutput(Ganti);
FuzzyRule *fuzzyRule455 = new FuzzyRule(455, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal455, Ganti455);
fuzzy->addFuzzyRule(fuzzyRule455);

// Rule 456 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak456 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak456->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal456 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal456->joinWithAND(DO_Normal_pH_Banyak456, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak456 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak456->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal456, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang456 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang456->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak456, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi456 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi456->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang456, EC_Tinggi); // Change here
FuzzyRuleConsequent *Ganti456 = new FuzzyRuleConsequent();
Ganti456->addOutput(Ganti);
FuzzyRule *fuzzyRule456 = new FuzzyRule(456, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi456, Ganti456);
fuzzy->addFuzzyRule(fuzzyRule456);

// Rule 457 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak457 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak457->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal457 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal457->joinWithAND(DO_Normal_pH_Banyak457, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak457 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak457->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal457, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam457 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam457->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak457, Jarak_Dalam); // Change here
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah457 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah457->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam457, EC_Rendah); // Change here
FuzzyRuleConsequent *Ganti457 = new FuzzyRuleConsequent();
Ganti457->addOutput(Ganti);
FuzzyRule *fuzzyRule457 = new FuzzyRule(457, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah457, Ganti457);
fuzzy->addFuzzyRule(fuzzyRule457);

// Rule 458 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak458 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak458->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal458 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal458->joinWithAND(DO_Normal_pH_Banyak458, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak458 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak458->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal458, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam458 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam458->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak458, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal458 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal458->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam458, EC_Normal); // Change here
FuzzyRuleConsequent *Ganti458 = new FuzzyRuleConsequent();
Ganti458->addOutput(Ganti);
FuzzyRule *fuzzyRule458 = new FuzzyRule(458, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal458, Ganti458);
fuzzy->addFuzzyRule(fuzzyRule458);

// Rule 459 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak459 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak459->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal459 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal459->joinWithAND(DO_Normal_pH_Banyak459, Suhu_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak459 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak459->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal459, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam459 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam459->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak459, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi459 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi459->joinWithAND(DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam459, EC_Tinggi); // Change here
FuzzyRuleConsequent *Ganti459 = new FuzzyRuleConsequent();
Ganti459->addOutput(Ganti);
FuzzyRule *fuzzyRule459 = new FuzzyRule(459, DO_Normal_pH_Banyak_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi459, Ganti459);
fuzzy->addFuzzyRule(fuzzyRule459);

// Rule 460 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak460 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak460->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak460 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak460->joinWithAND(DO_Normal_pH_Banyak460, Suhu_Banyak); // Change here
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah460 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah460->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak460, Kekeruhan_Rendah); // Change here
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal460 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal460->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah460, Jarak_Dangkal); // Change here
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah460 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah460->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal460, EC_Rendah); // Change here
FuzzyRuleConsequent *Ganti460 = new FuzzyRuleConsequent();
Ganti460->addOutput(Ganti);
FuzzyRule *fuzzyRule460 = new FuzzyRule(460, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah460, Ganti460);
fuzzy->addFuzzyRule(fuzzyRule460);

// Rule 461 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak461 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak461->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak461 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak461->joinWithAND(DO_Normal_pH_Banyak461, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah461 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah461->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak461, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal461 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal461->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah461, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal461 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal461->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal461, EC_Normal);
FuzzyRuleConsequent *Ganti461 = new FuzzyRuleConsequent();
Ganti461->addOutput(Ganti);
FuzzyRule *fuzzyRule461 = new FuzzyRule(461, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal461, Ganti461);
fuzzy->addFuzzyRule(fuzzyRule461);

// Rule 462 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak462 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak462->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak462 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak462->joinWithAND(DO_Normal_pH_Banyak462, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah462 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah462->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak462, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal462 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal462->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah462, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi462 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi462->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal462, EC_Tinggi);
FuzzyRuleConsequent *Ganti462 = new FuzzyRuleConsequent();
Ganti462->addOutput(Ganti);
FuzzyRule *fuzzyRule462 = new FuzzyRule(462, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi462, Ganti462);
fuzzy->addFuzzyRule(fuzzyRule462);

// Rule 463 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak463 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak463->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak463 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak463->joinWithAND(DO_Normal_pH_Banyak463, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah463 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah463->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak463, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang463 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang463->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah463, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah463 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah463->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang463, EC_Rendah);
FuzzyRuleConsequent *Ganti463 = new FuzzyRuleConsequent();
Ganti463->addOutput(Ganti);
FuzzyRule *fuzzyRule463 = new FuzzyRule(463, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah463, Ganti463);
fuzzy->addFuzzyRule(fuzzyRule463);

// Rule 464 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak464 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak464->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak464 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak464->joinWithAND(DO_Normal_pH_Banyak464, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah464 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah464->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak464, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang464 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang464->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah464, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal464 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal464->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang464, EC_Normal);
FuzzyRuleConsequent *Ganti464 = new FuzzyRuleConsequent();
Ganti464->addOutput(Ganti);
FuzzyRule *fuzzyRule464 = new FuzzyRule(464, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal464, Ganti464);
fuzzy->addFuzzyRule(fuzzyRule464);

// Rule 465 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak465 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak465->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak465 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak465->joinWithAND(DO_Normal_pH_Banyak465, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah465 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah465->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak465, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang465 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang465->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah465, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi465 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi465->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang465, EC_Tinggi);
FuzzyRuleConsequent *Ganti465 = new FuzzyRuleConsequent();
Ganti465->addOutput(Ganti);
FuzzyRule *fuzzyRule465 = new FuzzyRule(465, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi465, Ganti465);
fuzzy->addFuzzyRule(fuzzyRule465);

// Rule 466 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak466 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak466->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak466 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak466->joinWithAND(DO_Normal_pH_Banyak466, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah466 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah466->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak466, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam466 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam466->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah466, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah466 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah466->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam466, EC_Rendah);
FuzzyRuleConsequent *Ganti466 = new FuzzyRuleConsequent();
Ganti466->addOutput(Ganti);
FuzzyRule *fuzzyRule466 = new FuzzyRule(466, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah466, Ganti466);
fuzzy->addFuzzyRule(fuzzyRule466);

// Rule 467 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak467 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak467->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak467 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak467->joinWithAND(DO_Normal_pH_Banyak467, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah467 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah467->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak467, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam467 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam467->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah467, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal467 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal467->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam467, EC_Normal);
FuzzyRuleConsequent *Ganti467 = new FuzzyRuleConsequent();
Ganti467->addOutput(Ganti);
FuzzyRule *fuzzyRule467 = new FuzzyRule(467, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal467, Ganti467);
fuzzy->addFuzzyRule(fuzzyRule467);

// Rule 468 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak468 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak468->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak468 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak468->joinWithAND(DO_Normal_pH_Banyak468, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah468 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah468->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak468, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam468 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam468->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah468, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi468 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi468->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam468, EC_Tinggi);
FuzzyRuleConsequent *Ganti468 = new FuzzyRuleConsequent();
Ganti468->addOutput(Ganti);
FuzzyRule *fuzzyRule468 = new FuzzyRule(468, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi468, Ganti468);
fuzzy->addFuzzyRule(fuzzyRule468);

// Rule 469 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak469 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak469->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak469 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak469->joinWithAND(DO_Normal_pH_Banyak469, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal469 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal469->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak469, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal469 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal469->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal469, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah469 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah469->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal469, EC_Rendah);
FuzzyRuleConsequent *Ganti469 = new FuzzyRuleConsequent();
Ganti469->addOutput(Ganti);
FuzzyRule *fuzzyRule469 = new FuzzyRule(469, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah469, Ganti469);
fuzzy->addFuzzyRule(fuzzyRule469);

// Rule 470 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak470 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak470->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak470 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak470->joinWithAND(DO_Normal_pH_Banyak470, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal470 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal470->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak470, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal470 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal470->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal470, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal470 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal470->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal470, EC_Normal);
FuzzyRuleConsequent *Ganti470 = new FuzzyRuleConsequent();
Ganti470->addOutput(Ganti);
FuzzyRule *fuzzyRule470 = new FuzzyRule(470, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal470, Ganti470);
fuzzy->addFuzzyRule(fuzzyRule470);

// Rule 471 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak471 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak471->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak471 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak471->joinWithAND(DO_Normal_pH_Banyak471, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal471 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal471->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak471, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal471 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal471->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal471, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi471 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi471->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal471, EC_Tinggi);
FuzzyRuleConsequent *Ganti471 = new FuzzyRuleConsequent();
Ganti471->addOutput(Ganti);
FuzzyRule *fuzzyRule471 = new FuzzyRule(471, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi471, Ganti471);
fuzzy->addFuzzyRule(fuzzyRule471);

// Rule 472 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak472 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak472->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak472 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak472->joinWithAND(DO_Normal_pH_Banyak472, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal472 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal472->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak472, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang472 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang472->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal472, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah472 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah472->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang472, EC_Rendah);
FuzzyRuleConsequent *Ganti472 = new FuzzyRuleConsequent();
Ganti472->addOutput(Ganti);
FuzzyRule *fuzzyRule472 = new FuzzyRule(472, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah472, Ganti472);
fuzzy->addFuzzyRule(fuzzyRule472);

// Rule 473 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak473 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak473->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak473 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak473->joinWithAND(DO_Normal_pH_Banyak473, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal473 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal473->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak473, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang473 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang473->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal473, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal473 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal473->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang473, EC_Normal);
FuzzyRuleConsequent *Ganti473 = new FuzzyRuleConsequent();
Ganti473->addOutput(Ganti);
FuzzyRule *fuzzyRule473 = new FuzzyRule(473, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal473, Ganti473);
fuzzy->addFuzzyRule(fuzzyRule473);

// Rule 474 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak474 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak474->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak474 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak474->joinWithAND(DO_Normal_pH_Banyak474, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal474 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal474->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak474, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang474 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang474->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal474, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi474 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi474->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang474, EC_Tinggi);
FuzzyRuleConsequent *Ganti474 = new FuzzyRuleConsequent();
Ganti474->addOutput(Ganti);
FuzzyRule *fuzzyRule474 = new FuzzyRule(474, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi474, Ganti474);
fuzzy->addFuzzyRule(fuzzyRule474);

// Rule 475 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak475 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak475->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak475 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak475->joinWithAND(DO_Normal_pH_Banyak475, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal475 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal475->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak475, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam475 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam475->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal475, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah475 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah475->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam475, EC_Rendah);
FuzzyRuleConsequent *Ganti475 = new FuzzyRuleConsequent();
Ganti475->addOutput(Ganti);
FuzzyRule *fuzzyRule475 = new FuzzyRule(475, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah475, Ganti475);
fuzzy->addFuzzyRule(fuzzyRule475);

// Rule 476 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak476 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak476->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak476 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak476->joinWithAND(DO_Normal_pH_Banyak476, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal476 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal476->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak476, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam476 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam476->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal476, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal476 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal476->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam476, EC_Normal);
FuzzyRuleConsequent *Ganti476 = new FuzzyRuleConsequent();
Ganti476->addOutput(Ganti);
FuzzyRule *fuzzyRule476 = new FuzzyRule(476, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal476, Ganti476);
fuzzy->addFuzzyRule(fuzzyRule476);

// Rule 477 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak477 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak477->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak477 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak477->joinWithAND(DO_Normal_pH_Banyak477, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal477 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal477->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak477, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam477 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam477->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal477, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi477 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi477->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam477, EC_Tinggi);
FuzzyRuleConsequent *Ganti477 = new FuzzyRuleConsequent();
Ganti477->addOutput(Ganti);
FuzzyRule *fuzzyRule477 = new FuzzyRule(477, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi477, Ganti477);
fuzzy->addFuzzyRule(fuzzyRule477);

// Rule 478 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak478 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak478->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak478 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak478->joinWithAND(DO_Normal_pH_Banyak478, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak478 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak478->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak478, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal478 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal478->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak478, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah478 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah478->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal478, EC_Rendah);
FuzzyRuleConsequent *Ganti478 = new FuzzyRuleConsequent();
Ganti478->addOutput(Ganti);
FuzzyRule *fuzzyRule478 = new FuzzyRule(478, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah478, Ganti478);
fuzzy->addFuzzyRule(fuzzyRule478);

// Rule 479 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak479 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak479->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak479 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak479->joinWithAND(DO_Normal_pH_Banyak479, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak479 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak479->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak479, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal479 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal479->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak479, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal479 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal479->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal479, EC_Normal);
FuzzyRuleConsequent *Ganti479 = new FuzzyRuleConsequent();
Ganti479->addOutput(Ganti);
FuzzyRule *fuzzyRule479 = new FuzzyRule(479, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal479, Ganti479);
fuzzy->addFuzzyRule(fuzzyRule479);

// Rule 480 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak480 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak480->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak480 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak480->joinWithAND(DO_Normal_pH_Banyak480, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak480 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak480->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak480, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal480 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal480->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak480, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi480 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi480->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal480, EC_Tinggi);
FuzzyRuleConsequent *Ganti480 = new FuzzyRuleConsequent();
Ganti480->addOutput(Ganti);
FuzzyRule *fuzzyRule480 = new FuzzyRule(480, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi480, Ganti480);
fuzzy->addFuzzyRule(fuzzyRule480);

// Rule 481 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak481 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak481->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak481 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak481->joinWithAND(DO_Normal_pH_Banyak481, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak481 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak481->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak481, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang481 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang481->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak481, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah481 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah481->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang481, EC_Rendah);
FuzzyRuleConsequent *Ganti481 = new FuzzyRuleConsequent();
Ganti481->addOutput(Ganti);
FuzzyRule *fuzzyRule481 = new FuzzyRule(481, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah481, Ganti481);
fuzzy->addFuzzyRule(fuzzyRule481);

// Rule 482 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak482 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak482->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak482 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak482->joinWithAND(DO_Normal_pH_Banyak482, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak482 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak482->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak482, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang482 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang482->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak482, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal482 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal482->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang482, EC_Normal);
FuzzyRuleConsequent *Ganti482 = new FuzzyRuleConsequent();
Ganti482->addOutput(Ganti);
FuzzyRule *fuzzyRule482 = new FuzzyRule(482, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal482, Ganti482);
fuzzy->addFuzzyRule(fuzzyRule482);

// Rule 483 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak483 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak483->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak483 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak483->joinWithAND(DO_Normal_pH_Banyak483, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak483 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak483->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak483, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang483 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang483->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak483, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi483 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi483->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang483, EC_Tinggi);
FuzzyRuleConsequent *Ganti483 = new FuzzyRuleConsequent();
Ganti483->addOutput(Ganti);
FuzzyRule *fuzzyRule483 = new FuzzyRule(483, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi483, Ganti483);
fuzzy->addFuzzyRule(fuzzyRule483);

// Rule 484 (EC_Rendah)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak484 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak484->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak484 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak484->joinWithAND(DO_Normal_pH_Banyak484, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak484 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak484->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak484, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam484 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam484->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak484, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah484 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah484->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam484, EC_Rendah);
FuzzyRuleConsequent *Ganti484 = new FuzzyRuleConsequent();
Ganti484->addOutput(Ganti);
FuzzyRule *fuzzyRule484 = new FuzzyRule(484, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah484, Ganti484);
fuzzy->addFuzzyRule(fuzzyRule484);

// Rule 485 (EC_Normal)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak485 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak485->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak485 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak485->joinWithAND(DO_Normal_pH_Banyak485, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak485 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak485->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak485, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam485 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam485->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak485, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal485 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal485->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam485, EC_Normal);
FuzzyRuleConsequent *Ganti485 = new FuzzyRuleConsequent();
Ganti485->addOutput(Ganti);
FuzzyRule *fuzzyRule485 = new FuzzyRule(485, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal485, Ganti485);
fuzzy->addFuzzyRule(fuzzyRule485);

// Rule 486 (EC_Tinggi)
FuzzyRuleAntecedent *DO_Normal_pH_Banyak486 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak486->joinWithAND(DO_Normal, pH_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak486 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak486->joinWithAND(DO_Normal_pH_Banyak486, Suhu_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak486 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak486->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak486, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam486 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam486->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak486, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi486 = new FuzzyRuleAntecedent();
DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi486->joinWithAND(DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam486, EC_Tinggi);
FuzzyRuleConsequent *Ganti486 = new FuzzyRuleConsequent();
Ganti486->addOutput(Ganti);
FuzzyRule *fuzzyRule486 = new FuzzyRule(486, DO_Normal_pH_Banyak_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi486, Ganti486);
fuzzy->addFuzzyRule(fuzzyRule486);

// rule 487
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah487 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah487->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah487 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah487->joinWithAND(DO_Banyak_pH_Rendah487, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah487 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah487->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah487, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal487 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal487->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah487, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah487 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah487->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal487, EC_Rendah);
FuzzyRuleConsequent *Ganti487 = new FuzzyRuleConsequent();
Ganti487->addOutput(Ganti);
FuzzyRule *fuzzyRule487 = new FuzzyRule(487, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah487, Ganti487);
fuzzy->addFuzzyRule(fuzzyRule487);
// 488
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah488 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah488->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah488 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah488->joinWithAND(DO_Banyak_pH_Rendah488, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah488 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah488->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah488, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal488 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal488->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah488, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal488 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal488->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal488, EC_Normal);
FuzzyRuleConsequent *Ganti488 = new FuzzyRuleConsequent();
Ganti488->addOutput(Ganti);
FuzzyRule *fuzzyRule488 = new FuzzyRule(488, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal488, Ganti488);
fuzzy->addFuzzyRule(fuzzyRule488);
// 489
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah489 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah489->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah489 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah489->joinWithAND(DO_Banyak_pH_Rendah489, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah489 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah489->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah489, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal489 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal489->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah489, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi489 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi489->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal489, EC_Tinggi);
FuzzyRuleConsequent *Ganti489 = new FuzzyRuleConsequent();
Ganti489->addOutput(Ganti);
FuzzyRule *fuzzyRule489 = new FuzzyRule(489, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi489, Ganti489);
fuzzy->addFuzzyRule(fuzzyRule489);
// 490
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah490 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah490->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah490 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah490->joinWithAND(DO_Banyak_pH_Rendah490, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah490 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah490->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah490, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang490 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang490->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah490, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah490 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah490->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang490, EC_Rendah);
FuzzyRuleConsequent *Ganti490 = new FuzzyRuleConsequent();
Ganti490->addOutput(Ganti);
FuzzyRule *fuzzyRule490 = new FuzzyRule(490, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah490, Ganti490);
fuzzy->addFuzzyRule(fuzzyRule490);
// 491
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah491 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah491->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah491 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah491->joinWithAND(DO_Banyak_pH_Rendah491, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah491 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah491->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah491, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang491 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang491->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah491, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal491 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal491->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang491, EC_Normal);
FuzzyRuleConsequent *Ganti491 = new FuzzyRuleConsequent();
Ganti491->addOutput(Ganti);
FuzzyRule *fuzzyRule491 = new FuzzyRule(491, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal491, Ganti491);
fuzzy->addFuzzyRule(fuzzyRule491);
// 492
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah492 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah492->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah492 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah492->joinWithAND(DO_Banyak_pH_Rendah492, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah492 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah492->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah492, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang492 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang492->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah492, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi492 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi492->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang492, EC_Tinggi);
FuzzyRuleConsequent *Ganti492 = new FuzzyRuleConsequent();
Ganti492->addOutput(Ganti);
FuzzyRule *fuzzyRule492 = new FuzzyRule(492, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi492, Ganti492);
fuzzy->addFuzzyRule(fuzzyRule492);
// 493
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah493 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah493->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah493 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah493->joinWithAND(DO_Banyak_pH_Rendah493, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah493 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah493->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah493, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam493 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam493->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah493, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah493 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah493->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam493, EC_Rendah);
FuzzyRuleConsequent *Ganti493 = new FuzzyRuleConsequent();
Ganti493->addOutput(Ganti);
FuzzyRule *fuzzyRule493 = new FuzzyRule(493, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah493, Ganti493);
fuzzy->addFuzzyRule(fuzzyRule493);
// 494
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah494 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah494->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah494 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah494->joinWithAND(DO_Banyak_pH_Rendah494, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah494 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah494->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah494, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam494 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam494->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah494, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal494 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal494->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam494, EC_Normal);
FuzzyRuleConsequent *Ganti494 = new FuzzyRuleConsequent();
Ganti494->addOutput(Ganti);
FuzzyRule *fuzzyRule494 = new FuzzyRule(494, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal494, Ganti494);
fuzzy->addFuzzyRule(fuzzyRule494);
// 495
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah495 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah495->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah495 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah495->joinWithAND(DO_Banyak_pH_Rendah495, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah495 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah495->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah495, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam495 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam495->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah495, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi495 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi495->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam495, EC_Tinggi);
FuzzyRuleConsequent *Ganti495 = new FuzzyRuleConsequent();
Ganti495->addOutput(Ganti);
FuzzyRule *fuzzyRule495 = new FuzzyRule(495, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi495, Ganti495);
fuzzy->addFuzzyRule(fuzzyRule495);
// 496
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah496 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah496->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah496 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah496->joinWithAND(DO_Banyak_pH_Rendah496, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal496 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal496->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah496, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal496 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal496->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal496, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah496 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah496->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal496, EC_Rendah);
FuzzyRuleConsequent *Ganti496 = new FuzzyRuleConsequent();
Ganti496->addOutput(Ganti);
FuzzyRule *fuzzyRule496 = new FuzzyRule(496, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah496, Ganti496);
fuzzy->addFuzzyRule(fuzzyRule496);
// 497
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah497 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah497->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah497 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah497->joinWithAND(DO_Banyak_pH_Rendah497, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal497 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal497->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah497, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal497 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal497->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal497, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal497 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal497->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal497, EC_Normal);
FuzzyRuleConsequent *Ganti497 = new FuzzyRuleConsequent();
Ganti497->addOutput(Ganti);
FuzzyRule *fuzzyRule497 = new FuzzyRule(497, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal497, Ganti497);
fuzzy->addFuzzyRule(fuzzyRule497);
// 498
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah498 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah498->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah498 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah498->joinWithAND(DO_Banyak_pH_Rendah498, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal498 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal498->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah498, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal498 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal498->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal498, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi498 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi498->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal498, EC_Tinggi);
FuzzyRuleConsequent *Ganti498 = new FuzzyRuleConsequent();
Ganti498->addOutput(Ganti);
FuzzyRule *fuzzyRule498 = new FuzzyRule(498, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi498, Ganti498);
fuzzy->addFuzzyRule(fuzzyRule498);
// 499
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah499 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah499->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah499 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah499->joinWithAND(DO_Banyak_pH_Rendah499, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal499 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal499->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah499, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang499 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang499->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal499, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah499 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah499->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang499, EC_Rendah);
FuzzyRuleConsequent *Ganti499 = new FuzzyRuleConsequent();
Ganti499->addOutput(Ganti);
FuzzyRule *fuzzyRule499 = new FuzzyRule(499, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah499, Ganti499);
fuzzy->addFuzzyRule(fuzzyRule499);
// 500
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah500 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah500->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah500 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah500->joinWithAND(DO_Banyak_pH_Rendah500, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal500 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal500->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah500, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang500 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang500->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal500, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal500 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal500->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang500, EC_Normal);
FuzzyRuleConsequent *Ganti500 = new FuzzyRuleConsequent();
Ganti500->addOutput(Ganti);
FuzzyRule *fuzzyRule500 = new FuzzyRule(500, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal500, Ganti500);
fuzzy->addFuzzyRule(fuzzyRule500);
// 501
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah501 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah501->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah501 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah501->joinWithAND(DO_Banyak_pH_Rendah501, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal501 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal501->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah501, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang501 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang501->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal501, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi501 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi501->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang501, EC_Tinggi);
FuzzyRuleConsequent *Ganti501 = new FuzzyRuleConsequent();
Ganti501->addOutput(Ganti);
FuzzyRule *fuzzyRule501 = new FuzzyRule(501, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi501, Ganti501);
fuzzy->addFuzzyRule(fuzzyRule501);
// 502
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah502 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah502->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah502 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah502->joinWithAND(DO_Banyak_pH_Rendah502, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal502 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal502->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah502, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam502 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam502->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal502, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah502 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah502->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam502, EC_Rendah);
FuzzyRuleConsequent *Ganti502 = new FuzzyRuleConsequent();
Ganti502->addOutput(Ganti);
FuzzyRule *fuzzyRule502 = new FuzzyRule(502, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah502, Ganti502);
fuzzy->addFuzzyRule(fuzzyRule502);
// 503
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah503 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah503->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah503 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah503->joinWithAND(DO_Banyak_pH_Rendah503, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal503 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal503->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah503, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam503 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam503->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal503, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal503 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal503->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam503, EC_Normal);
FuzzyRuleConsequent *Ganti503 = new FuzzyRuleConsequent();
Ganti503->addOutput(Ganti);
FuzzyRule *fuzzyRule503 = new FuzzyRule(503, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal503, Ganti503);
fuzzy->addFuzzyRule(fuzzyRule503);
// 504
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah504 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah504->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah504 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah504->joinWithAND(DO_Banyak_pH_Rendah504, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal504 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal504->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah504, Kekeruhan_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam504 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam504->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal504, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi504 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi504->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam504, EC_Tinggi);
FuzzyRuleConsequent *Ganti504 = new FuzzyRuleConsequent();
Ganti504->addOutput(Ganti);
FuzzyRule *fuzzyRule504 = new FuzzyRule(504, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi504, Ganti504);
fuzzy->addFuzzyRule(fuzzyRule504);
// 505
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah505 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah505->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah505 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah505->joinWithAND(DO_Banyak_pH_Rendah505, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak505 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak505->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah505, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal505 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal505->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak505, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah505 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah505->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal505, EC_Rendah);
FuzzyRuleConsequent *Ganti505 = new FuzzyRuleConsequent();
Ganti505->addOutput(Ganti);
FuzzyRule *fuzzyRule505 = new FuzzyRule(505, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah505, Ganti505);
fuzzy->addFuzzyRule(fuzzyRule505);
// 506
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah506 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah506->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah506 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah506->joinWithAND(DO_Banyak_pH_Rendah506, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak506 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak506->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah506, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal506 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal506->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak506, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal506 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal506->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal506, EC_Normal);
FuzzyRuleConsequent *Ganti506 = new FuzzyRuleConsequent();
Ganti506->addOutput(Ganti);
FuzzyRule *fuzzyRule506 = new FuzzyRule(506, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal506, Ganti506);
fuzzy->addFuzzyRule(fuzzyRule506);
// 507
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah507 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah507->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah507 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah507->joinWithAND(DO_Banyak_pH_Rendah507, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak507 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak507->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah507, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal507 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal507->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak507, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi507 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi507->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal507, EC_Tinggi);
FuzzyRuleConsequent *Ganti507 = new FuzzyRuleConsequent();
Ganti507->addOutput(Ganti);
FuzzyRule *fuzzyRule507 = new FuzzyRule(507, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi507, Ganti507);
fuzzy->addFuzzyRule(fuzzyRule507);
// 508
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah508 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah508->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah508 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah508->joinWithAND(DO_Banyak_pH_Rendah508, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak508 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak508->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah508, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang508 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang508->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak508, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah508 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah508->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang508, EC_Rendah);
FuzzyRuleConsequent *Ganti508 = new FuzzyRuleConsequent();
Ganti508->addOutput(Ganti);
FuzzyRule *fuzzyRule508 = new FuzzyRule(508, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah508, Ganti508);
fuzzy->addFuzzyRule(fuzzyRule508);
// 509
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah509 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah509->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah509 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah509->joinWithAND(DO_Banyak_pH_Rendah509, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak509 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak509->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah509, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang509 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang509->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak509, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal509 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal509->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang509, EC_Normal);
FuzzyRuleConsequent *Ganti509 = new FuzzyRuleConsequent();
Ganti509->addOutput(Ganti);
FuzzyRule *fuzzyRule509 = new FuzzyRule(509, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal509, Ganti509);
fuzzy->addFuzzyRule(fuzzyRule509);
// 510
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah510 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah510->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah510 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah510->joinWithAND(DO_Banyak_pH_Rendah510, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak510 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak510->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah510, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang510 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang510->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak510, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi510 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi510->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang510, EC_Tinggi);
FuzzyRuleConsequent *Ganti510 = new FuzzyRuleConsequent();
Ganti510->addOutput(Ganti);
FuzzyRule *fuzzyRule510 = new FuzzyRule(510, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi510, Ganti510);
fuzzy->addFuzzyRule(fuzzyRule510);
// 511
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah511 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah511->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah511 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah511->joinWithAND(DO_Banyak_pH_Rendah511, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak511 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak511->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah511, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam511 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam511->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak511, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah511 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah511->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam511, EC_Rendah);
FuzzyRuleConsequent *Ganti511 = new FuzzyRuleConsequent();
Ganti511->addOutput(Ganti);
FuzzyRule *fuzzyRule511 = new FuzzyRule(511, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah511, Ganti511);
fuzzy->addFuzzyRule(fuzzyRule511);
// 512
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah512 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah512->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah512 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah512->joinWithAND(DO_Banyak_pH_Rendah512, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak512 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak512->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah512, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam512 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam512->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak512, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal512 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal512->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam512, EC_Normal);
FuzzyRuleConsequent *Ganti512 = new FuzzyRuleConsequent();
Ganti512->addOutput(Ganti);
FuzzyRule *fuzzyRule512 = new FuzzyRule(512, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal512, Ganti512);
fuzzy->addFuzzyRule(fuzzyRule512);
// 513
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah513 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah513->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah513 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah513->joinWithAND(DO_Banyak_pH_Rendah513, Suhu_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak513 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak513->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah513, Kekeruhan_Banyak);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam513 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam513->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak513, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi513 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi513->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam513, EC_Tinggi);
FuzzyRuleConsequent *Ganti513 = new FuzzyRuleConsequent();
Ganti513->addOutput(Ganti);
FuzzyRule *fuzzyRule513 = new FuzzyRule(513, DO_Banyak_pH_Rendah_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi513, Ganti513);
fuzzy->addFuzzyRule(fuzzyRule513);
// 514
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah514 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah514->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal514 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal514->joinWithAND(DO_Banyak_pH_Rendah514, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah514 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah514->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal514, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal514 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal514->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah514, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah514 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah514->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal514, EC_Rendah);
FuzzyRuleConsequent *Ganti514 = new FuzzyRuleConsequent();
Ganti514->addOutput(Ganti);
FuzzyRule *fuzzyRule514 = new FuzzyRule(514, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah514, Ganti514);
fuzzy->addFuzzyRule(fuzzyRule514);
// 515
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah515 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah515->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal515 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal515->joinWithAND(DO_Banyak_pH_Rendah515, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah515 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah515->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal515, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal515 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal515->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah515, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal515 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal515->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal515, EC_Normal);
FuzzyRuleConsequent *Ganti515 = new FuzzyRuleConsequent();
Ganti515->addOutput(Ganti);
FuzzyRule *fuzzyRule515 = new FuzzyRule(515, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal515, Ganti515);
fuzzy->addFuzzyRule(fuzzyRule515);
// 516
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah516 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah516->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal516 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal516->joinWithAND(DO_Banyak_pH_Rendah516, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah516 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah516->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal516, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal516 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal516->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah516, Jarak_Dangkal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi516 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi516->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal516, EC_Tinggi);
FuzzyRuleConsequent *Ganti516 = new FuzzyRuleConsequent();
Ganti516->addOutput(Ganti);
FuzzyRule *fuzzyRule516 = new FuzzyRule(516, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi516, Ganti516);
fuzzy->addFuzzyRule(fuzzyRule516);
// 517
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah517 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah517->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal517 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal517->joinWithAND(DO_Banyak_pH_Rendah517, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah517 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah517->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal517, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang517 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang517->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah517, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah517 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah517->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang517, EC_Rendah);
FuzzyRuleConsequent *Ganti517 = new FuzzyRuleConsequent();
Ganti517->addOutput(Ganti);
FuzzyRule *fuzzyRule517 = new FuzzyRule(517, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah517, Ganti517);
fuzzy->addFuzzyRule(fuzzyRule517);
// 518
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah518 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah518->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal518 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal518->joinWithAND(DO_Banyak_pH_Rendah518, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah518 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah518->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal518, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang518 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang518->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah518, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal518 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal518->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang518, EC_Normal);
FuzzyRuleConsequent *Ganti518 = new FuzzyRuleConsequent();
Ganti518->addOutput(Ganti);
FuzzyRule *fuzzyRule518 = new FuzzyRule(518, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal518, Ganti518);
fuzzy->addFuzzyRule(fuzzyRule518);
// 519
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah519 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah519->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal519 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal519->joinWithAND(DO_Banyak_pH_Rendah519, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah519 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah519->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal519, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang519 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang519->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah519, Jarak_Sedang);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi519 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi519->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang519, EC_Tinggi);
FuzzyRuleConsequent *Ganti519 = new FuzzyRuleConsequent();
Ganti519->addOutput(Ganti);
FuzzyRule *fuzzyRule519 = new FuzzyRule(519, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi519, Ganti519);
fuzzy->addFuzzyRule(fuzzyRule519);
// 520
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah520 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah520->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal520 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal520->joinWithAND(DO_Banyak_pH_Rendah520, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah520 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah520->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal520, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam520 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam520->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah520, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah520 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah520->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam520, EC_Rendah);
FuzzyRuleConsequent *Ganti520 = new FuzzyRuleConsequent();
Ganti520->addOutput(Ganti);
FuzzyRule *fuzzyRule520 = new FuzzyRule(520, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah520, Ganti520);
fuzzy->addFuzzyRule(fuzzyRule520);
// 521
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah521 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah521->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal521 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal521->joinWithAND(DO_Banyak_pH_Rendah521, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah521 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah521->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal521, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam521 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam521->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah521, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal521 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal521->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam521, EC_Normal);
FuzzyRuleConsequent *Ganti521 = new FuzzyRuleConsequent();
Ganti521->addOutput(Ganti);
FuzzyRule *fuzzyRule521 = new FuzzyRule(521, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal521, Ganti521);
fuzzy->addFuzzyRule(fuzzyRule521);
// 522
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah522 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah522->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal522 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal522->joinWithAND(DO_Banyak_pH_Rendah522, Suhu_Normal);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah522 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah522->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal522, Kekeruhan_Rendah);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam522 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam522->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah522, Jarak_Dalam);
FuzzyRuleAntecedent *DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi522 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi522->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam522, EC_Tinggi);
FuzzyRuleConsequent *Ganti522 = new FuzzyRuleConsequent();
Ganti522->addOutput(Ganti);
FuzzyRule *fuzzyRule522 = new FuzzyRule(522, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi522, Ganti522);
fuzzy->addFuzzyRule(fuzzyRule522);
// 523
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah523 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah523->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal523 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal523->joinWithAND(DO_Banyak_pH_Rendah523, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal523 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal523->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal523, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal523 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal523->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal523, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah523 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah523->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal523, EC_Rendah);
FuzzyRuleConsequent* Ganti523 = new FuzzyRuleConsequent();
Ganti523->addOutput(Ganti);
FuzzyRule* fuzzyRule523 = new FuzzyRule(523, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah523, Ganti523);
fuzzy->addFuzzyRule(fuzzyRule523);
// 524
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah524 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah524->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal524 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal524->joinWithAND(DO_Banyak_pH_Rendah524, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal524 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal524->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal524, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal524 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal524->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal524, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal524 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal524->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal524, EC_Normal);
FuzzyRuleConsequent* Ganti524 = new FuzzyRuleConsequent();
Ganti524->addOutput(Ganti);
FuzzyRule* fuzzyRule524 = new FuzzyRule(524, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal524, Ganti524);
fuzzy->addFuzzyRule(fuzzyRule524);
// 525
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah525 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah525->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal525 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal525->joinWithAND(DO_Banyak_pH_Rendah525, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal525 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal525->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal525, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal525 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal525->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal525, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi525 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi525->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal525, EC_Tinggi);
FuzzyRuleConsequent* Ganti525 = new FuzzyRuleConsequent();
Ganti525->addOutput(Ganti);
FuzzyRule* fuzzyRule525 = new FuzzyRule(525, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi525, Ganti525);
fuzzy->addFuzzyRule(fuzzyRule525);
// 526
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah526 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah526->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal526 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal526->joinWithAND(DO_Banyak_pH_Rendah526, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal526 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal526->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal526, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang526 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang526->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal526, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah526 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah526->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang526, EC_Rendah);
FuzzyRuleConsequent* Ganti526 = new FuzzyRuleConsequent();
Ganti526->addOutput(Ganti);
FuzzyRule* fuzzyRule526 = new FuzzyRule(526, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah526, Ganti526);
fuzzy->addFuzzyRule(fuzzyRule526);
// 527
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah527 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah527->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal527 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal527->joinWithAND(DO_Banyak_pH_Rendah527, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal527 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal527->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal527, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang527 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang527->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal527, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal527 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal527->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang527, EC_Normal);
FuzzyRuleConsequent* Ganti527 = new FuzzyRuleConsequent();
Ganti527->addOutput(Ganti);
FuzzyRule* fuzzyRule527 = new FuzzyRule(527, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal527, Ganti527);
fuzzy->addFuzzyRule(fuzzyRule527);
// 528
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah528 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah528->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal528 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal528->joinWithAND(DO_Banyak_pH_Rendah528, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal528 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal528->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal528, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang528 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang528->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal528, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi528 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi528->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang528, EC_Tinggi);
FuzzyRuleConsequent* Ganti528 = new FuzzyRuleConsequent();
Ganti528->addOutput(Ganti);
FuzzyRule* fuzzyRule528 = new FuzzyRule(528, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi528, Ganti528);
fuzzy->addFuzzyRule(fuzzyRule528);
// 529
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah529 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah529->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal529 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal529->joinWithAND(DO_Banyak_pH_Rendah529, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal529 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal529->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal529, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam529 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam529->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal529, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah529 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah529->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam529, EC_Rendah);
FuzzyRuleConsequent* Ganti529 = new FuzzyRuleConsequent();
Ganti529->addOutput(Ganti);
FuzzyRule* fuzzyRule529 = new FuzzyRule(529, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah529, Ganti529);
fuzzy->addFuzzyRule(fuzzyRule529);
// 530
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah530 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah530->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal530 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal530->joinWithAND(DO_Banyak_pH_Rendah530, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal530 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal530->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal530, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam530 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam530->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal530, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal530 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal530->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam530, EC_Normal);
FuzzyRuleConsequent* Ganti530 = new FuzzyRuleConsequent();
Ganti530->addOutput(Ganti);
FuzzyRule* fuzzyRule530 = new FuzzyRule(530, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal530, Ganti530);
fuzzy->addFuzzyRule(fuzzyRule530);
// 531
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah531 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah531->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal531 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal531->joinWithAND(DO_Banyak_pH_Rendah531, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal531 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal531->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal531, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam531 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam531->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal531, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi531 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi531->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam531, EC_Tinggi);
FuzzyRuleConsequent* Ganti531 = new FuzzyRuleConsequent();
Ganti531->addOutput(Ganti);
FuzzyRule* fuzzyRule531 = new FuzzyRule(531, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi531, Ganti531);
fuzzy->addFuzzyRule(fuzzyRule531);
// 532
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah532 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah532->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal532 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal532->joinWithAND(DO_Banyak_pH_Rendah532, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak532 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak532->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal532, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal532 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal532->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak532, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah532 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah532->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal532, EC_Rendah);
FuzzyRuleConsequent* Ganti532 = new FuzzyRuleConsequent();
Ganti532->addOutput(Ganti);
FuzzyRule* fuzzyRule532 = new FuzzyRule(532, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah532, Ganti532);
fuzzy->addFuzzyRule(fuzzyRule532);
// 533
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah533 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah533->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal533 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal533->joinWithAND(DO_Banyak_pH_Rendah533, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak533 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak533->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal533, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal533 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal533->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak533, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal533 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal533->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal533, EC_Normal);
FuzzyRuleConsequent* Ganti533 = new FuzzyRuleConsequent();
Ganti533->addOutput(Ganti);
FuzzyRule* fuzzyRule533 = new FuzzyRule(533, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal533, Ganti533);
fuzzy->addFuzzyRule(fuzzyRule533);
// 534
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah534 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah534->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal534 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal534->joinWithAND(DO_Banyak_pH_Rendah534, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak534 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak534->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal534, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal534 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal534->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak534, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi534 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi534->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal534, EC_Tinggi);
FuzzyRuleConsequent* Ganti534 = new FuzzyRuleConsequent();
Ganti534->addOutput(Ganti);
FuzzyRule* fuzzyRule534 = new FuzzyRule(534, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi534, Ganti534);
fuzzy->addFuzzyRule(fuzzyRule534);
// 535
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah535 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah535->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal535 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal535->joinWithAND(DO_Banyak_pH_Rendah535, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak535 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak535->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal535, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang535 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang535->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak535, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah535 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah535->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang535, EC_Rendah);
FuzzyRuleConsequent* Ganti535 = new FuzzyRuleConsequent();
Ganti535->addOutput(Ganti);
FuzzyRule* fuzzyRule535 = new FuzzyRule(535, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah535, Ganti535);
fuzzy->addFuzzyRule(fuzzyRule535);
// 536
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah536 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah536->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal536 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal536->joinWithAND(DO_Banyak_pH_Rendah536, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak536 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak536->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal536, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang536 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang536->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak536, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal536 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal536->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang536, EC_Normal);
FuzzyRuleConsequent* Ganti536 = new FuzzyRuleConsequent();
Ganti536->addOutput(Ganti);
FuzzyRule* fuzzyRule536 = new FuzzyRule(536, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal536, Ganti536);
fuzzy->addFuzzyRule(fuzzyRule536);
// 537
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah537 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah537->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal537 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal537->joinWithAND(DO_Banyak_pH_Rendah537, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak537 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak537->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal537, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang537 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang537->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak537, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi537 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi537->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang537, EC_Tinggi);
FuzzyRuleConsequent* Ganti537 = new FuzzyRuleConsequent();
Ganti537->addOutput(Ganti);
FuzzyRule* fuzzyRule537 = new FuzzyRule(537, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi537, Ganti537);
fuzzy->addFuzzyRule(fuzzyRule537);
// 538
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah538 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah538->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal538 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal538->joinWithAND(DO_Banyak_pH_Rendah538, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak538 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak538->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal538, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam538 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam538->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak538, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah538 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah538->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam538, EC_Rendah);
FuzzyRuleConsequent* Ganti538 = new FuzzyRuleConsequent();
Ganti538->addOutput(Ganti);
FuzzyRule* fuzzyRule538 = new FuzzyRule(538, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah538, Ganti538);
fuzzy->addFuzzyRule(fuzzyRule538);
// 539
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah539 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah539->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal539 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal539->joinWithAND(DO_Banyak_pH_Rendah539, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak539 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak539->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal539, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam539 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam539->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak539, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal539 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal539->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam539, EC_Normal);
FuzzyRuleConsequent* Ganti539 = new FuzzyRuleConsequent();
Ganti539->addOutput(Ganti);
FuzzyRule* fuzzyRule539 = new FuzzyRule(539, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal539, Ganti539);
fuzzy->addFuzzyRule(fuzzyRule539);
// 540
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah540 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah540->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal540 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal540->joinWithAND(DO_Banyak_pH_Rendah540, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak540 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak540->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal540, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam540 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam540->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak540, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi540 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi540->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam540, EC_Tinggi);
FuzzyRuleConsequent* Ganti540 = new FuzzyRuleConsequent();
Ganti540->addOutput(Ganti);
FuzzyRule* fuzzyRule540 = new FuzzyRule(540, DO_Banyak_pH_Rendah_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi540, Ganti540);
fuzzy->addFuzzyRule(fuzzyRule540);
// 541
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah541 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah541->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak541 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak541->joinWithAND(DO_Banyak_pH_Rendah541, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah541 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah541->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak541, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal541 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal541->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah541, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah541 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah541->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal541, EC_Rendah);
FuzzyRuleConsequent* Ganti541 = new FuzzyRuleConsequent();
Ganti541->addOutput(Ganti);
FuzzyRule* fuzzyRule541 = new FuzzyRule(541, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah541, Ganti541);
fuzzy->addFuzzyRule(fuzzyRule541);
// 542
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah542 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah542->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak542 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak542->joinWithAND(DO_Banyak_pH_Rendah542, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah542 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah542->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak542, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal542 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal542->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah542, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal542 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal542->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal542, EC_Normal);
FuzzyRuleConsequent* Ganti542 = new FuzzyRuleConsequent();
Ganti542->addOutput(Ganti);
FuzzyRule* fuzzyRule542 = new FuzzyRule(542, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal542, Ganti542);
fuzzy->addFuzzyRule(fuzzyRule542);
// 543
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah543 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah543->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak543 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak543->joinWithAND(DO_Banyak_pH_Rendah543, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah543 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah543->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak543, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal543 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal543->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah543, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi543 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi543->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal543, EC_Tinggi);
FuzzyRuleConsequent* Ganti543 = new FuzzyRuleConsequent();
Ganti543->addOutput(Ganti);
FuzzyRule* fuzzyRule543 = new FuzzyRule(543, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi543, Ganti543);
fuzzy->addFuzzyRule(fuzzyRule543);
// 544
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah544 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah544->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak544 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak544->joinWithAND(DO_Banyak_pH_Rendah544, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah544 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah544->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak544, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang544 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang544->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah544, Jarak_Sedang); // Mengubah Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah544 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah544->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang544, EC_Rendah);
FuzzyRuleConsequent* Ganti544 = new FuzzyRuleConsequent();
Ganti544->addOutput(Ganti);
FuzzyRule* fuzzyRule544 = new FuzzyRule(544, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah544, Ganti544);
fuzzy->addFuzzyRule(fuzzyRule544);
// 545
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah545 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah545->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak545 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak545->joinWithAND(DO_Banyak_pH_Rendah545, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah545 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah545->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak545, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang545 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang545->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah545, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal545 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal545->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang545, EC_Normal);
FuzzyRuleConsequent* Ganti545 = new FuzzyRuleConsequent();
Ganti545->addOutput(Ganti);
FuzzyRule* fuzzyRule545 = new FuzzyRule(545, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal545, Ganti545);
fuzzy->addFuzzyRule(fuzzyRule545);
// 546
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah546 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah546->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak546 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak546->joinWithAND(DO_Banyak_pH_Rendah546, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah546 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah546->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak546, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang546 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang546->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah546, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi546 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi546->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang546, EC_Tinggi);
FuzzyRuleConsequent* Ganti546 = new FuzzyRuleConsequent();
Ganti546->addOutput(Ganti);
FuzzyRule* fuzzyRule546 = new FuzzyRule(546, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi546, Ganti546);
fuzzy->addFuzzyRule(fuzzyRule546);
// 547
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah547 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah547->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak547 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak547->joinWithAND(DO_Banyak_pH_Rendah547, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah547 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah547->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak547, Kekeruhan_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam547 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam547->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah547, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah547 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah547->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah547, EC_Rendah);
FuzzyRuleConsequent* Ganti547 = new FuzzyRuleConsequent();
Ganti547->addOutput(Ganti);
FuzzyRule* fuzzyRule547 = new FuzzyRule(547, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah547, Ganti547);
fuzzy->addFuzzyRule(fuzzyRule547);
// 548
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah548 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah548->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak548 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak548->joinWithAND(DO_Banyak_pH_Rendah548, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah548 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah548->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak548, Kekeruhan_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam548 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam548->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah548, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal548 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal548->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam548, EC_Normal); 
FuzzyRuleConsequent* Ganti548 = new FuzzyRuleConsequent();
Ganti548->addOutput(Ganti);
FuzzyRule* fuzzyRule548 = new FuzzyRule(548, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal548, Ganti548);
fuzzy->addFuzzyRule(fuzzyRule548);
// 549
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah549 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah549->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak549 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak549->joinWithAND(DO_Banyak_pH_Rendah549, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah549 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah549->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak549, Kekeruhan_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam549 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam549->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah549, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi549 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi549->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam549, EC_Tinggi);
FuzzyRuleConsequent* Ganti549 = new FuzzyRuleConsequent();
Ganti549->addOutput(Ganti);
FuzzyRule* fuzzyRule549 = new FuzzyRule(549, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi549, Ganti549);
fuzzy->addFuzzyRule(fuzzyRule549);
// 550
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah550 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah550->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak550 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak550->joinWithAND(DO_Banyak_pH_Rendah550, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal550 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal550->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak550, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal550 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal550->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal550, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah550 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah550->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal550, EC_Rendah);
FuzzyRuleConsequent* Ganti550 = new FuzzyRuleConsequent();
Ganti550->addOutput(Ganti);
FuzzyRule* fuzzyRule550 = new FuzzyRule(550, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah550, Ganti550);
fuzzy->addFuzzyRule(fuzzyRule550);
// 551
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah551 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah551->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak551 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak551->joinWithAND(DO_Banyak_pH_Rendah551, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal551 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal551->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak551, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal551 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal551->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal551, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal551 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal551->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal551, EC_Normal);
FuzzyRuleConsequent* Ganti551 = new FuzzyRuleConsequent();
Ganti551->addOutput(Ganti);
FuzzyRule* fuzzyRule551 = new FuzzyRule(551, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal551, Ganti551);
fuzzy->addFuzzyRule(fuzzyRule551);
// 552
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah552 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah552->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak552 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak552->joinWithAND(DO_Banyak_pH_Rendah552, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal552 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal552->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak552, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal552 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal552->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal552, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi552 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi552->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal552, EC_Tinggi); 
FuzzyRuleConsequent* Ganti552 = new FuzzyRuleConsequent();
Ganti552->addOutput(Ganti);
FuzzyRule* fuzzyRule552 = new FuzzyRule(552, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi552, Ganti552);
fuzzy->addFuzzyRule(fuzzyRule552);
// 553
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah553 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah553->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak553 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak553->joinWithAND(DO_Banyak_pH_Rendah553, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal553 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal553->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak553, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang553 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang553->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal553, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah553 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah553->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang553, EC_Rendah);
FuzzyRuleConsequent* Ganti553 = new FuzzyRuleConsequent();
Ganti553->addOutput(Ganti);
FuzzyRule* fuzzyRule553 = new FuzzyRule(553, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah553, Ganti553);
fuzzy->addFuzzyRule(fuzzyRule553);
// 554
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah554 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah554->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak554 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak554->joinWithAND(DO_Banyak_pH_Rendah554, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal554 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal554->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak554, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang554 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang554->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal554, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal554 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal554->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang554, EC_Normal);
FuzzyRuleConsequent* Ganti554 = new FuzzyRuleConsequent();
Ganti554->addOutput(Ganti);
FuzzyRule* fuzzyRule554 = new FuzzyRule(554, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal554, Ganti554);
fuzzy->addFuzzyRule(fuzzyRule554);
// 555
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah555 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah555->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak555 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak555->joinWithAND(DO_Banyak_pH_Rendah555, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal555 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal555->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak555, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang555 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang555->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal555, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi555 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi555->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang555, EC_Tinggi);
FuzzyRuleConsequent* Ganti555 = new FuzzyRuleConsequent();
Ganti555->addOutput(Ganti);
FuzzyRule* fuzzyRule555 = new FuzzyRule(555, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi555, Ganti555);
fuzzy->addFuzzyRule(fuzzyRule555);
// 556
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah556 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah556->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak556 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak556->joinWithAND(DO_Banyak_pH_Rendah556, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal556 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal556->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak556, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam556 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam556->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal556, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah556 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah556->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam556, EC_Rendah);
FuzzyRuleConsequent* Ganti556 = new FuzzyRuleConsequent();
Ganti556->addOutput(Ganti);
FuzzyRule* fuzzyRule556 = new FuzzyRule(556, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah556, Ganti556);
fuzzy->addFuzzyRule(fuzzyRule556);
// 557
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah557 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah557->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak557 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak557->joinWithAND(DO_Banyak_pH_Rendah557, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal557 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal557->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak557, Kekeruhan_Normal); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam557 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam557->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal557, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal557 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal557->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam557, EC_Normal);
FuzzyRuleConsequent* Ganti557 = new FuzzyRuleConsequent();
Ganti557->addOutput(Ganti);
FuzzyRule* fuzzyRule557 = new FuzzyRule(557, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal557, Ganti557);
fuzzy->addFuzzyRule(fuzzyRule557);
// 558
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah558 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah558->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak558 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak558->joinWithAND(DO_Banyak_pH_Rendah558, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal558 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal558->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak558, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam558 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam558->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal558, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi558 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi558->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam558, EC_Tinggi);
FuzzyRuleConsequent* Ganti558 = new FuzzyRuleConsequent();
Ganti558->addOutput(Ganti);
FuzzyRule* fuzzyRule558 = new FuzzyRule(558, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi558, Ganti558);
fuzzy->addFuzzyRule(fuzzyRule558);
// 559
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah559 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah559->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak559 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak559->joinWithAND(DO_Banyak_pH_Rendah559, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak559 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak559->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak559, Kekeruhan_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal559 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal559->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak559, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah559 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah559->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal559, EC_Rendah);
FuzzyRuleConsequent* Ganti559 = new FuzzyRuleConsequent();
Ganti559->addOutput(Ganti);
FuzzyRule* fuzzyRule559 = new FuzzyRule(559, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah559, Ganti559);
fuzzy->addFuzzyRule(fuzzyRule559);
// 560
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah560 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah560->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak560 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak560->joinWithAND(DO_Banyak_pH_Rendah560, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak560 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak560->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak560, Kekeruhan_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal560 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal560->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak560, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal560 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal560->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal560, EC_Normal);
FuzzyRuleConsequent* Ganti560 = new FuzzyRuleConsequent();
Ganti560->addOutput(Ganti);
FuzzyRule* fuzzyRule560 = new FuzzyRule(560, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal560, Ganti560);
fuzzy->addFuzzyRule(fuzzyRule560);
// 561
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah561 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah561->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak561 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak561->joinWithAND(DO_Banyak_pH_Rendah561, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak561 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak561->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak561, Kekeruhan_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal561 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal561->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak561, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi561 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi561->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal561, EC_Tinggi);
FuzzyRuleConsequent* Ganti561 = new FuzzyRuleConsequent();
Ganti561->addOutput(Ganti);
FuzzyRule* fuzzyRule561 = new FuzzyRule(561, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi561, Ganti561);
fuzzy->addFuzzyRule(fuzzyRule561);
// 562
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah562 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah562->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak562 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak562->joinWithAND(DO_Banyak_pH_Rendah562, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak562 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak562->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak562, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang562 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang562->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak562, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah562 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah562->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang562, EC_Rendah);
FuzzyRuleConsequent* Ganti562 = new FuzzyRuleConsequent();
Ganti562->addOutput(Ganti);
FuzzyRule* fuzzyRule562 = new FuzzyRule(562, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah562, Ganti562);
fuzzy->addFuzzyRule(fuzzyRule562);
// 563
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah563 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah563->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak563 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak563->joinWithAND(DO_Banyak_pH_Rendah563, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak563 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak563->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak563, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang563 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang563->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak563, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal563 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal563->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang563, EC_Normal);
FuzzyRuleConsequent* Ganti563 = new FuzzyRuleConsequent();
Ganti563->addOutput(Ganti);
FuzzyRule* fuzzyRule563 = new FuzzyRule(563, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal563, Ganti563);
fuzzy->addFuzzyRule(fuzzyRule563);
// 564
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah564 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah564->joinWithAND(DO_Banyak, pH_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak564 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak564->joinWithAND(DO_Banyak_pH_Rendah564, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak564 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak564->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak564, Kekeruhan_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang564 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang564->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak564, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi564 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi564->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang564, EC_Tinggi);
FuzzyRuleConsequent* Ganti564 = new FuzzyRuleConsequent();
Ganti564->addOutput(Ganti);
FuzzyRule* fuzzyRule564 = new FuzzyRule(564, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi564, Ganti564);
fuzzy->addFuzzyRule(fuzzyRule564);
// 565
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah565 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah565->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak565 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak565->joinWithAND(DO_Banyak_pH_Rendah565, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak565 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak565->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak565, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam565 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam565->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak565, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah565 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah565->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam565, EC_Rendah);
FuzzyRuleConsequent* Ganti565 = new FuzzyRuleConsequent();
Ganti565->addOutput(Ganti);
FuzzyRule* fuzzyRule565 = new FuzzyRule(565, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah565, Ganti565);
fuzzy->addFuzzyRule(fuzzyRule565);
// 566
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah566 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah566->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak566 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak566->joinWithAND(DO_Banyak_pH_Rendah566, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak566 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak566->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak566, Kekeruhan_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam566 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam566->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak566, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal566 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal566->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam566, EC_Normal);
FuzzyRuleConsequent* Ganti566 = new FuzzyRuleConsequent();
Ganti566->addOutput(Ganti);
FuzzyRule* fuzzyRule566 = new FuzzyRule(566, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal566, Ganti566);
fuzzy->addFuzzyRule(fuzzyRule566);
// 567
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah567 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah567->joinWithAND(DO_Banyak, pH_Rendah); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak567 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak567->joinWithAND(DO_Banyak_pH_Rendah567, Suhu_Banyak); 
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak567 = new FuzzyRuleAntecedent(); 
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak567->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak567, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam567 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam567->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak567, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi567 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi567->joinWithAND(DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam567, EC_Tinggi);
FuzzyRuleConsequent* Ganti567 = new FuzzyRuleConsequent();
Ganti567->addOutput(Ganti);
FuzzyRule* fuzzyRule567 = new FuzzyRule(567, DO_Banyak_pH_Rendah_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi567, Ganti567);
fuzzy->addFuzzyRule(fuzzyRule567);
// 568
FuzzyRuleAntecedent* DO_Banyak_pH_Normal568 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal568->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah568 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah568->joinWithAND(DO_Banyak_pH_Normal568, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah568 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah568->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah568, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal568 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal568->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah568, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah568 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah568->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal568, EC_Rendah);
FuzzyRuleConsequent* Ganti568 = new FuzzyRuleConsequent();
Ganti568->addOutput(Ganti);
FuzzyRule* fuzzyRule568 = new FuzzyRule(568, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah568, Ganti568);
fuzzy->addFuzzyRule(fuzzyRule568);
// 569
FuzzyRuleAntecedent* DO_Banyak_pH_Normal569 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal569->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah569 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah569->joinWithAND(DO_Banyak_pH_Normal569, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah569 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah569->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah569, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal569 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal569->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah569, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal569 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal569->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal569, EC_Normal);
FuzzyRuleConsequent* Ganti569 = new FuzzyRuleConsequent();
Ganti569->addOutput(Ganti);
FuzzyRule* fuzzyRule569 = new FuzzyRule(569, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal569, Ganti569);
fuzzy->addFuzzyRule(fuzzyRule569);
// 570
FuzzyRuleAntecedent* DO_Banyak_pH_Normal570 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal570->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah570 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah570->joinWithAND(DO_Banyak_pH_Normal570, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah570 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah570->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah570, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal570 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal570->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah570, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi570 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi570->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal570, EC_Tinggi);
FuzzyRuleConsequent* Ganti570 = new FuzzyRuleConsequent();
Ganti570->addOutput(Ganti);
FuzzyRule* fuzzyRule570 = new FuzzyRule(570, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi570, Ganti570);
fuzzy->addFuzzyRule(fuzzyRule570);
// 571
FuzzyRuleAntecedent* DO_Banyak_pH_Normal571 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal571->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah571 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah571->joinWithAND(DO_Banyak_pH_Normal571, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah571 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah571->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah571, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang571 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang571->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah571, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah571 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah571->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang571, EC_Rendah);
FuzzyRuleConsequent* Ganti571 = new FuzzyRuleConsequent();
Ganti571->addOutput(Ganti);
FuzzyRule* fuzzyRule571 = new FuzzyRule(571, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah571, Ganti571);
fuzzy->addFuzzyRule(fuzzyRule571);
// 572
FuzzyRuleAntecedent* DO_Banyak_pH_Normal572 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal572->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah572 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah572->joinWithAND(DO_Banyak_pH_Normal572, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah572 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah572->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah572, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang572 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang572->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah572, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal572 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal572->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang572, EC_Normal);
FuzzyRuleConsequent* Ganti572 = new FuzzyRuleConsequent();
Ganti572->addOutput(Ganti);
FuzzyRule* fuzzyRule572 = new FuzzyRule(572, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal572, Ganti572);
fuzzy->addFuzzyRule(fuzzyRule572);
// 573
FuzzyRuleAntecedent* DO_Banyak_pH_Normal573 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal573->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah573 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah573->joinWithAND(DO_Banyak_pH_Normal573, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah573 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah573->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah573, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang573 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang573->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah573, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi573 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi573->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang573, EC_Tinggi);
FuzzyRuleConsequent* Ganti573 = new FuzzyRuleConsequent();
Ganti573->addOutput(Ganti);
FuzzyRule* fuzzyRule573 = new FuzzyRule(573, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi573, Ganti573);
fuzzy->addFuzzyRule(fuzzyRule573);
// 574
FuzzyRuleAntecedent* DO_Banyak_pH_Normal574 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal574->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah574 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah574->joinWithAND(DO_Banyak_pH_Normal574, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah574 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah574->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah574, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam574 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam574->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah574, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah574 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah574->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam574, EC_Rendah);
FuzzyRuleConsequent* Ganti574 = new FuzzyRuleConsequent();
Ganti574->addOutput(Ganti);
FuzzyRule* fuzzyRule574 = new FuzzyRule(574, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah574, Ganti574);
fuzzy->addFuzzyRule(fuzzyRule574);
// 575
FuzzyRuleAntecedent* DO_Banyak_pH_Normal575 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal575->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah575 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah575->joinWithAND(DO_Banyak_pH_Normal575, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah575 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah575->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah575, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam575 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam575->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah575, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal575 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal575->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam575, EC_Normal);
FuzzyRuleConsequent* Ganti575 = new FuzzyRuleConsequent();
Ganti575->addOutput(Ganti);
FuzzyRule* fuzzyRule575 = new FuzzyRule(575, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal575, Ganti575);
fuzzy->addFuzzyRule(fuzzyRule575);
// 576
FuzzyRuleAntecedent* DO_Banyak_pH_Normal576 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal576->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah576 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah576->joinWithAND(DO_Banyak_pH_Normal576, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah576 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah576->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah576, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam576 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam576->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah576, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi576 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi576->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam576, EC_Tinggi);
FuzzyRuleConsequent* Ganti576 = new FuzzyRuleConsequent();
Ganti576->addOutput(Ganti);
FuzzyRule* fuzzyRule576 = new FuzzyRule(576, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi576, Ganti576);
fuzzy->addFuzzyRule(fuzzyRule576);

// 577
FuzzyRuleAntecedent* DO_Banyak_pH_Normal577 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal577->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah577 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah577->joinWithAND(DO_Banyak_pH_Normal577, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal577 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal577->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah577, Kekeruhan_Normal); // Mengubah Kekeruhan_Banyak menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal577 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal577->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal577, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah577 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah577->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal577, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti577 = new FuzzyRuleConsequent();
Ganti577->addOutput(Ganti);
FuzzyRule* fuzzyRule577 = new FuzzyRule(577, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah577, Ganti577);
fuzzy->addFuzzyRule(fuzzyRule577);
// 578
FuzzyRuleAntecedent* DO_Banyak_pH_Normal578 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal578->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah578 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah578->joinWithAND(DO_Banyak_pH_Normal578, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal578 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal578->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah578, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal578 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal578->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal578, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal578 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal578->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal578, EC_Normal);
FuzzyRuleConsequent* Ganti578 = new FuzzyRuleConsequent();
Ganti578->addOutput(Ganti);
FuzzyRule* fuzzyRule578 = new FuzzyRule(578, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal578, Ganti578);
fuzzy->addFuzzyRule(fuzzyRule578);
// 579
FuzzyRuleAntecedent* DO_Banyak_pH_Normal579 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal579->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah579 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah579->joinWithAND(DO_Banyak_pH_Normal579, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal579 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal579->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah579, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal579 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal579->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal579, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi579 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi579->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal579, EC_Tinggi);
FuzzyRuleConsequent* Ganti579 = new FuzzyRuleConsequent();
Ganti579->addOutput(Ganti);
FuzzyRule* fuzzyRule579 = new FuzzyRule(579, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi579, Ganti579);
fuzzy->addFuzzyRule(fuzzyRule579);
// 580
FuzzyRuleAntecedent* DO_Banyak_pH_Normal580 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal580->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah580 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah580->joinWithAND(DO_Banyak_pH_Normal580, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal580 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal580->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah580, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang580 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang580->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal580, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah580 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah580->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang580, EC_Rendah);
FuzzyRuleConsequent* Ganti580 = new FuzzyRuleConsequent();
Ganti580->addOutput(Ganti);
FuzzyRule* fuzzyRule580 = new FuzzyRule(580, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah580, Ganti580);
fuzzy->addFuzzyRule(fuzzyRule580);
// 581
FuzzyRuleAntecedent* DO_Banyak_pH_Normal581 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal581->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah581 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah581->joinWithAND(DO_Banyak_pH_Normal581, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal581 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal581->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah581, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang581 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang581->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal581, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal581 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal581->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang581, EC_Normal);
FuzzyRuleConsequent* Ganti581 = new FuzzyRuleConsequent();
Ganti581->addOutput(Ganti);
FuzzyRule* fuzzyRule581 = new FuzzyRule(581, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal581, Ganti581);
fuzzy->addFuzzyRule(fuzzyRule581);
// 582
FuzzyRuleAntecedent* DO_Banyak_pH_Normal582 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal582->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah582 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah582->joinWithAND(DO_Banyak_pH_Normal582, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal582 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal582->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah582, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang582 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang582->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal582, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi582 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi582->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang582, EC_Tinggi);
FuzzyRuleConsequent* Ganti582 = new FuzzyRuleConsequent();
Ganti582->addOutput(Ganti);
FuzzyRule* fuzzyRule582 = new FuzzyRule(582, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi582, Ganti582);
fuzzy->addFuzzyRule(fuzzyRule582);
// 583
FuzzyRuleAntecedent* DO_Banyak_pH_Normal583 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal583->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah583 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah583->joinWithAND(DO_Banyak_pH_Normal583, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal583 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal583->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah583, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam583 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam583->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal583, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah583 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah583->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam583, EC_Rendah);
FuzzyRuleConsequent* Ganti583 = new FuzzyRuleConsequent();
Ganti583->addOutput(Ganti);
FuzzyRule* fuzzyRule583 = new FuzzyRule(583, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah583, Ganti583);
fuzzy->addFuzzyRule(fuzzyRule583);
// 584
FuzzyRuleAntecedent* DO_Banyak_pH_Normal584 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal584->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah584 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah584->joinWithAND(DO_Banyak_pH_Normal584, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal584 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal584->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah584, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam584 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam584->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal584, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal584 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal584->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam584, EC_Normal);
FuzzyRuleConsequent* Ganti584 = new FuzzyRuleConsequent();
Ganti584->addOutput(Ganti);
FuzzyRule* fuzzyRule584 = new FuzzyRule(584, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Normal584, Ganti584);
fuzzy->addFuzzyRule(fuzzyRule584);
// 585
FuzzyRuleAntecedent* DO_Banyak_pH_Normal585 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal585->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah585 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah585->joinWithAND(DO_Banyak_pH_Normal585, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal585 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal585->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah585, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam585 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam585->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal585, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi585 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi585->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam585, EC_Tinggi);
FuzzyRuleConsequent* Ganti585 = new FuzzyRuleConsequent();
Ganti585->addOutput(Ganti);
FuzzyRule* fuzzyRule585 = new FuzzyRule(585, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi585, Ganti585);
fuzzy->addFuzzyRule(fuzzyRule585);

// 586
FuzzyRuleAntecedent* DO_Banyak_pH_Normal586 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal586->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah586 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah586->joinWithAND(DO_Banyak_pH_Normal586, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak586 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak586->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah586, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal586 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal586->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak586, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah586 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah586->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal586, EC_Rendah);
FuzzyRuleConsequent* Ganti586 = new FuzzyRuleConsequent();
Ganti586->addOutput(Ganti);
FuzzyRule* fuzzyRule586 = new FuzzyRule(586, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah586, Ganti586);
fuzzy->addFuzzyRule(fuzzyRule586);
// 587
FuzzyRuleAntecedent* DO_Banyak_pH_Normal587 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal587->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah587 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah587->joinWithAND(DO_Banyak_pH_Normal587, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak587 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak587->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah587, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal587 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal587->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak587, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal587 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal587->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal587, EC_Normal);
FuzzyRuleConsequent* Ganti587 = new FuzzyRuleConsequent();
Ganti587->addOutput(Ganti);
FuzzyRule* fuzzyRule587 = new FuzzyRule(587, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal587, Ganti587);
fuzzy->addFuzzyRule(fuzzyRule587);
// 588
FuzzyRuleAntecedent* DO_Banyak_pH_Normal588 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal588->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah588 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah588->joinWithAND(DO_Banyak_pH_Normal588, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak588 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak588->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah588, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal588 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal588->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak588, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi588 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi588->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal588, EC_Tinggi);
FuzzyRuleConsequent* Ganti588 = new FuzzyRuleConsequent();
Ganti588->addOutput(Ganti);
FuzzyRule* fuzzyRule588 = new FuzzyRule(588, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi588, Ganti588);
fuzzy->addFuzzyRule(fuzzyRule588);
// 589
FuzzyRuleAntecedent* DO_Banyak_pH_Normal589 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal589->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah589 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah589->joinWithAND(DO_Banyak_pH_Normal589, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak589 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak589->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah589, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang589 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang589->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak589, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah589 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah589->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang589, EC_Rendah);
FuzzyRuleConsequent* Ganti589 = new FuzzyRuleConsequent();
Ganti589->addOutput(Ganti);
FuzzyRule* fuzzyRule589 = new FuzzyRule(589, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah589, Ganti589);
fuzzy->addFuzzyRule(fuzzyRule589);
// 590
FuzzyRuleAntecedent* DO_Banyak_pH_Normal590 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal590->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah590 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah590->joinWithAND(DO_Banyak_pH_Normal590, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak590 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak590->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah590, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang590 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang590->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak590, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal590 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal590->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang590, EC_Normal);
FuzzyRuleConsequent* Ganti590 = new FuzzyRuleConsequent();
Ganti590->addOutput(Ganti);
FuzzyRule* fuzzyRule590 = new FuzzyRule(590, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal590, Ganti590);
fuzzy->addFuzzyRule(fuzzyRule590);
// 591
FuzzyRuleAntecedent* DO_Banyak_pH_Normal591 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal591->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah591 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah591->joinWithAND(DO_Banyak_pH_Normal591, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak591 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak591->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah591, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang591 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang591->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak591, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi591 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi591->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang591, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti591 = new FuzzyRuleConsequent();
Ganti591->addOutput(Ganti);
FuzzyRule* fuzzyRule591 = new FuzzyRule(591, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi591, Ganti591);
fuzzy->addFuzzyRule(fuzzyRule591);
// 592
FuzzyRuleAntecedent* DO_Banyak_pH_Normal592 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal592->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah592 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah592->joinWithAND(DO_Banyak_pH_Normal592, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak592 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak592->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah592, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam592 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam592->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak592, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah592 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah592->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam592, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti592 = new FuzzyRuleConsequent();
Ganti592->addOutput(Ganti);
FuzzyRule* fuzzyRule592 = new FuzzyRule(592, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah592, Ganti592);
fuzzy->addFuzzyRule(fuzzyRule592);
// 593
FuzzyRuleAntecedent* DO_Banyak_pH_Normal593 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal593->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah593 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah593->joinWithAND(DO_Banyak_pH_Normal593, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak593 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak593->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah593, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam593 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam593->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak593, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal593 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal593->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam593, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti593 = new FuzzyRuleConsequent();
Ganti593->addOutput(Ganti);
FuzzyRule* fuzzyRule593 = new FuzzyRule(593, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal593, Ganti593);
fuzzy->addFuzzyRule(fuzzyRule593);
// 594
FuzzyRuleAntecedent* DO_Banyak_pH_Normal594 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal594->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah594 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah594->joinWithAND(DO_Banyak_pH_Normal594, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak594 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak594->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah594, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam594 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam594->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak594, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi594 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi594->joinWithAND(DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam594, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti594 = new FuzzyRuleConsequent();
Ganti594->addOutput(Ganti);
FuzzyRule* fuzzyRule594 = new FuzzyRule(594, DO_Banyak_pH_Normal_Suhu_Rendah_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi594, Ganti594);
fuzzy->addFuzzyRule(fuzzyRule594);
// 595
FuzzyRuleAntecedent* DO_Banyak_pH_Normal595 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal595->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal595 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal595->joinWithAND(DO_Banyak_pH_Normal595, Suhu_Normal); // Mengubah Suhu_Rendah menjadi Suhu_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah595 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah595->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal595, Kekeruhan_Rendah); // Mengubah Kekeruhan_Banyak menjadi Kekeruhan_Rendah
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal595 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal595->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah595, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah595 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah595->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal595, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti595 = new FuzzyRuleConsequent();
Ganti595->addOutput(Ganti);
FuzzyRule* fuzzyRule595 = new FuzzyRule(595, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah595, Ganti595);
fuzzy->addFuzzyRule(fuzzyRule595);
// 596
FuzzyRuleAntecedent* DO_Banyak_pH_Normal596 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal596->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal596 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal596->joinWithAND(DO_Banyak_pH_Normal596, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah596 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah596->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal596, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal596 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal596->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah596, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal596 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal596->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal596, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti596 = new FuzzyRuleConsequent();
Ganti596->addOutput(Ganti);
FuzzyRule* fuzzyRule596 = new FuzzyRule(596, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal596, Ganti596);
fuzzy->addFuzzyRule(fuzzyRule596);
// 597
FuzzyRuleAntecedent* DO_Banyak_pH_Normal597 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal597->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal597 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal597->joinWithAND(DO_Banyak_pH_Normal597, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah597 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah597->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal597, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal597 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal597->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah597, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi597 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi597->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal597, EC_Tinggi); // Kondisi EC_Tinggi
FuzzyRuleConsequent* Ganti597 = new FuzzyRuleConsequent();
Ganti597->addOutput(Ganti);
FuzzyRule* fuzzyRule597 = new FuzzyRule(597, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi597, Ganti597);
fuzzy->addFuzzyRule(fuzzyRule597);
// 598
FuzzyRuleAntecedent* DO_Banyak_pH_Normal598 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal598->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal598 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal598->joinWithAND(DO_Banyak_pH_Normal598, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah598 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah598->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal598, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang598 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang598->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah598, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah598 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah598->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang598, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti598 = new FuzzyRuleConsequent();
Ganti598->addOutput(Ganti);
FuzzyRule* fuzzyRule598 = new FuzzyRule(598, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah598, Ganti598);
fuzzy->addFuzzyRule(fuzzyRule598);
// 599
FuzzyRuleAntecedent* DO_Banyak_pH_Normal599 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal599->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal599 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal599->joinWithAND(DO_Banyak_pH_Normal599, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah599 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah599->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal599, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang599 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang599->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah599, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal599 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal599->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang599, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti599 = new FuzzyRuleConsequent();
Ganti599->addOutput(Ganti);
FuzzyRule* fuzzyRule599 = new FuzzyRule(599, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal599, Ganti599);
fuzzy->addFuzzyRule(fuzzyRule599);
// 600
FuzzyRuleAntecedent* DO_Banyak_pH_Normal600 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal600->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal600 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal600->joinWithAND(DO_Banyak_pH_Normal600, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah600 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah600->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal600, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang600 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang600->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah600, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi600 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi600->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang600, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti600 = new FuzzyRuleConsequent();
Ganti600->addOutput(Ganti);
FuzzyRule* fuzzyRule600 = new FuzzyRule(600, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi600, Ganti600);
fuzzy->addFuzzyRule(fuzzyRule600);
// 601
FuzzyRuleAntecedent* DO_Banyak_pH_Normal601 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal601->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal601 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal601->joinWithAND(DO_Banyak_pH_Normal601, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah601 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah601->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal601, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam601 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam601->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah601, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah601 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah601->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam601, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti601 = new FuzzyRuleConsequent();
Ganti601->addOutput(Ganti);
FuzzyRule* fuzzyRule601 = new FuzzyRule(601, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah601, Ganti601);
fuzzy->addFuzzyRule(fuzzyRule601);
// 602
FuzzyRuleAntecedent* DO_Banyak_pH_Normal602 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal602->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal602 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal602->joinWithAND(DO_Banyak_pH_Normal602, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah602 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah602->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal602, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam602 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam602->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah602, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal602 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal602->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam602, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti602 = new FuzzyRuleConsequent();
Ganti602->addOutput(Ganti);
FuzzyRule* fuzzyRule602 = new FuzzyRule(602, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal602, Ganti602);
fuzzy->addFuzzyRule(fuzzyRule602);
// 603
FuzzyRuleAntecedent* DO_Banyak_pH_Normal603 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal603->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal603 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal603->joinWithAND(DO_Banyak_pH_Normal603, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah603 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah603->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal603, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam603 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam603->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah603, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi603 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi603->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam603, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti603 = new FuzzyRuleConsequent();
Ganti603->addOutput(Ganti);
FuzzyRule* fuzzyRule603 = new FuzzyRule(603, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi603, Ganti603);
fuzzy->addFuzzyRule(fuzzyRule603);
// 604
FuzzyRuleAntecedent* DO_Banyak_pH_Normal604 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal604->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal604 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal604->joinWithAND(DO_Banyak_pH_Normal604, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal604 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal604->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal604, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal604 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal604->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal604, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah604 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah604->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal604, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti604 = new FuzzyRuleConsequent();
Ganti604->addOutput(Ganti);
FuzzyRule* fuzzyRule604 = new FuzzyRule(604, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah604, Ganti604);
fuzzy->addFuzzyRule(fuzzyRule604);
// 605
FuzzyRuleAntecedent* DO_Banyak_pH_Normal605 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal605->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal605 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal605->joinWithAND(DO_Banyak_pH_Normal605, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal605 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal605->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal605, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal605 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal605->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal605, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal605 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal605->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal605, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti605 = new FuzzyRuleConsequent();
Ganti605->addOutput(Ganti);
FuzzyRule* fuzzyRule605 = new FuzzyRule(605, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal605, Ganti605);
fuzzy->addFuzzyRule(fuzzyRule605);
// 606
FuzzyRuleAntecedent* DO_Banyak_pH_Normal606 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal606->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal606 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal606->joinWithAND(DO_Banyak_pH_Normal606, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal606 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal606->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal606, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal606 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal606->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal606, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi606 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi606->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal606, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti606 = new FuzzyRuleConsequent();
Ganti606->addOutput(Ganti);
FuzzyRule* fuzzyRule606 = new FuzzyRule(606, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi606, Ganti606);
fuzzy->addFuzzyRule(fuzzyRule606);
// 607
FuzzyRuleAntecedent* DO_Banyak_pH_Normal607 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal607->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal607 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal607->joinWithAND(DO_Banyak_pH_Normal607, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal607 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal607->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal607, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang607 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang607->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal607, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah607 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah607->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang607, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti607 = new FuzzyRuleConsequent();
Ganti607->addOutput(Ganti);
FuzzyRule* fuzzyRule607 = new FuzzyRule(607, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah607, Ganti607);
fuzzy->addFuzzyRule(fuzzyRule607);
// 608
FuzzyRuleAntecedent* DO_Banyak_pH_Normal608 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal608->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal608 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal608->joinWithAND(DO_Banyak_pH_Normal608, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal608 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal608->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal608, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang608 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang608->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal608, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal608 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal608->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang608, EC_Normal); // Kondisi EC_Normal
FuzzyRuleConsequent* Ganti608 = new FuzzyRuleConsequent();
Ganti608->addOutput(Ganti);
FuzzyRule* fuzzyRule608 = new FuzzyRule(608, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Normal608, Ganti608);
fuzzy->addFuzzyRule(fuzzyRule608);
// 609
FuzzyRuleAntecedent* DO_Banyak_pH_Normal609 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal609->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal609 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal609->joinWithAND(DO_Banyak_pH_Normal609, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal609 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal609->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal609, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang609 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang609->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal609, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi609 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi609->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang609, EC_Tinggi); // Kondisi EC_Tinggi
FuzzyRuleConsequent* Ganti609 = new FuzzyRuleConsequent();
Ganti609->addOutput(Ganti);
FuzzyRule* fuzzyRule609 = new FuzzyRule(609, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi609, Ganti609);
fuzzy->addFuzzyRule(fuzzyRule609);
// 610
FuzzyRuleAntecedent* DO_Banyak_pH_Normal610 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal610->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal610 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal610->joinWithAND(DO_Banyak_pH_Normal610, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal610 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal610->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal610, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam610 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam610->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal610, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah610 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah610->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam610, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti610 = new FuzzyRuleConsequent();
Ganti610->addOutput(Ganti);
FuzzyRule* fuzzyRule610 = new FuzzyRule(610, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah610, Ganti610);
fuzzy->addFuzzyRule(fuzzyRule610);
// 611
FuzzyRuleAntecedent* DO_Banyak_pH_Normal611 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal611->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal611 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal611->joinWithAND(DO_Banyak_pH_Normal611, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal611 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal611->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal611, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam611 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam611->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal611, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal611 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal611->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam611, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti611 = new FuzzyRuleConsequent();
Ganti611->addOutput(Ganti);
FuzzyRule* fuzzyRule611 = new FuzzyRule(611, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Normal611, Ganti611);
fuzzy->addFuzzyRule(fuzzyRule611);
// 612
FuzzyRuleAntecedent* DO_Banyak_pH_Normal612 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal612->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal612 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal612->joinWithAND(DO_Banyak_pH_Normal612, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal612 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal612->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal612, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam612 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam612->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal612, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi612 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi612->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam612, EC_Tinggi); // Kondisi EC_Tinggi
FuzzyRuleConsequent* Ganti612 = new FuzzyRuleConsequent();
Ganti612->addOutput(Ganti);
FuzzyRule* fuzzyRule612 = new FuzzyRule(612, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi612, Ganti612);
fuzzy->addFuzzyRule(fuzzyRule612);
// 613
FuzzyRuleAntecedent* DO_Banyak_pH_Normal613 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal613->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal613 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal613->joinWithAND(DO_Banyak_pH_Normal613, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak613 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak613->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal613, Kekeruhan_Banyak); // Mengubah Kekeruhan_Normal menjadi Kekeruhan_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal613 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal613->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak613, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah613 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah613->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal613, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti613 = new FuzzyRuleConsequent();
Ganti613->addOutput(Ganti);
FuzzyRule* fuzzyRule613 = new FuzzyRule(613, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah613, Ganti613);
fuzzy->addFuzzyRule(fuzzyRule613);
// 614
FuzzyRuleAntecedent* DO_Banyak_pH_Normal614 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal614->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal614 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal614->joinWithAND(DO_Banyak_pH_Normal614, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak614 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak614->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal614, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal614 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal614->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak614, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal614 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal614->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal614, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti614 = new FuzzyRuleConsequent();
Ganti614->addOutput(Ganti);
FuzzyRule* fuzzyRule614 = new FuzzyRule(614, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal614, Ganti614);
fuzzy->addFuzzyRule(fuzzyRule614);
// 615
FuzzyRuleAntecedent* DO_Banyak_pH_Normal615 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal615->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal615 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal615->joinWithAND(DO_Banyak_pH_Normal615, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak615 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak615->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal615, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal615 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal615->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak615, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi615 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi615->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal615, EC_Tinggi); // Kondisi EC_Tinggi
FuzzyRuleConsequent* Ganti615 = new FuzzyRuleConsequent();
Ganti615->addOutput(Ganti);
FuzzyRule* fuzzyRule615 = new FuzzyRule(615, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi615, Ganti615);
fuzzy->addFuzzyRule(fuzzyRule615);
// 616
FuzzyRuleAntecedent* DO_Banyak_pH_Normal616 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal616->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal616 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal616->joinWithAND(DO_Banyak_pH_Normal616, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak616 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak616->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal616, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang616 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang616->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak616, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah616 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah616->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang616, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti616 = new FuzzyRuleConsequent();
Ganti616->addOutput(Ganti);
FuzzyRule* fuzzyRule616 = new FuzzyRule(616, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah616, Ganti616);
fuzzy->addFuzzyRule(fuzzyRule616);
// 617
FuzzyRuleAntecedent* DO_Banyak_pH_Normal617 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal617->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal617 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal617->joinWithAND(DO_Banyak_pH_Normal617, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak617 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak617->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal617, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang617 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang617->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak617, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal617 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal617->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang617, EC_Normal); // Mengubah EC_Normal
FuzzyRuleConsequent* Ganti617 = new FuzzyRuleConsequent();
Ganti617->addOutput(Ganti);
FuzzyRule* fuzzyRule617 = new FuzzyRule(617, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal617, Ganti617);
fuzzy->addFuzzyRule(fuzzyRule617);
// 618
FuzzyRuleAntecedent* DO_Banyak_pH_Normal618 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal618->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal618 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal618->joinWithAND(DO_Banyak_pH_Normal618, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak618 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak618->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal618, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang618 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang618->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak618, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi618 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi618->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang618, EC_Tinggi); // Mengubah EC_Tinggi
FuzzyRuleConsequent* Ganti618 = new FuzzyRuleConsequent();
Ganti618->addOutput(Ganti);
FuzzyRule* fuzzyRule618 = new FuzzyRule(618, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi618, Ganti618);
fuzzy->addFuzzyRule(fuzzyRule618);
// 619
FuzzyRuleAntecedent* DO_Banyak_pH_Normal619 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal619->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal619 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal619->joinWithAND(DO_Banyak_pH_Normal619, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak619 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak619->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal619, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam619 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam619->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak619, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah619 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah619->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam619, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti619 = new FuzzyRuleConsequent();
Ganti619->addOutput(Ganti);
FuzzyRule* fuzzyRule619 = new FuzzyRule(619, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah619, Ganti619);
fuzzy->addFuzzyRule(fuzzyRule619);
// 620
FuzzyRuleAntecedent* DO_Banyak_pH_Normal620 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal620->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal620 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal620->joinWithAND(DO_Banyak_pH_Normal620, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak620 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak620->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal620, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam620 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam620->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak620, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal620 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal620->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam620, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti620 = new FuzzyRuleConsequent();
Ganti620->addOutput(Ganti);
FuzzyRule* fuzzyRule620 = new FuzzyRule(620, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal620, Ganti620);
fuzzy->addFuzzyRule(fuzzyRule620);
// 621 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal621 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal621->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal621 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal621->joinWithAND(DO_Banyak_pH_Normal621, Suhu_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak621 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak621->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal621, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam621 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam621->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak621, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi621 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi621->joinWithAND(DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam621, EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti621 = new FuzzyRuleConsequent();
Ganti621->addOutput(Ganti);
FuzzyRule* fuzzyRule621 = new FuzzyRule(621, DO_Banyak_pH_Normal_Suhu_Normal_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi621, Ganti621);
fuzzy->addFuzzyRule(fuzzyRule621);
// 622
FuzzyRuleAntecedent* DO_Banyak_pH_Normal622 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal622->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak622 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak622->joinWithAND(DO_Banyak_pH_Normal622, Suhu_Banyak); // Mengubah Suhu_Normal menjadi Suhu_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah622 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah622->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak622, Kekeruhan_Rendah); // Mengubah Kekeruhan_Banyak menjadi Kekeruhan_Rendah
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal622 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal622->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah622, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah622 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah622->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal622, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti622 = new FuzzyRuleConsequent();
Ganti622->addOutput(Ganti);
FuzzyRule* fuzzyRule622 = new FuzzyRule(622, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah622, Ganti622);
fuzzy->addFuzzyRule(fuzzyRule622);
// 623 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal623 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal623->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak623 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak623->joinWithAND(DO_Banyak_pH_Normal623, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah623 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah623->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak623, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal623 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal623->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah623, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal623 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal623->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal623, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti623 = new FuzzyRuleConsequent();
Ganti623->addOutput(Ganti);
FuzzyRule* fuzzyRule623 = new FuzzyRule(623, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal623, Ganti623);
fuzzy->addFuzzyRule(fuzzyRule623);
// 624 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal624 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal624->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak624 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak624->joinWithAND(DO_Banyak_pH_Normal624, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah624 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah624->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak624, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal624 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal624->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah624, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi624 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi624->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal624, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti624 = new FuzzyRuleConsequent();
Ganti624->addOutput(Ganti);
FuzzyRule* fuzzyRule624 = new FuzzyRule(624, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi624, Ganti624);
fuzzy->addFuzzyRule(fuzzyRule624);
// 625 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal625 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal625->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak625 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak625->joinWithAND(DO_Banyak_pH_Normal625, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah625 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah625->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak625, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang625 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang625->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah625, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah625 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah625->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang625, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti625 = new FuzzyRuleConsequent();
Ganti625->addOutput(Ganti);
FuzzyRule* fuzzyRule625 = new FuzzyRule(625, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah625, Ganti625);
fuzzy->addFuzzyRule(fuzzyRule625);
// 626 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal626 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal626->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak626 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak626->joinWithAND(DO_Banyak_pH_Normal626, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah626 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah626->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak626, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang626 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang626->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah626, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal626 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal626->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang626, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti626 = new FuzzyRuleConsequent();
Ganti626->addOutput(Ganti);
FuzzyRule* fuzzyRule626 = new FuzzyRule(626, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal626, Ganti626);
fuzzy->addFuzzyRule(fuzzyRule626);
// 627 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal627 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal627->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak627 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak627->joinWithAND(DO_Banyak_pH_Normal627, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah627 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah627->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak627, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang627 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang627->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah627, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi627 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi627->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang627, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti627 = new FuzzyRuleConsequent();
Ganti627->addOutput(Ganti);
FuzzyRule* fuzzyRule627 = new FuzzyRule(627, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi627, Ganti627);
fuzzy->addFuzzyRule(fuzzyRule627);
// 628 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal628 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal628->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak628 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak628->joinWithAND(DO_Banyak_pH_Normal628, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah628 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah628->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak628, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam628 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam628->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah628, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah628 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah628->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam628, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti628 = new FuzzyRuleConsequent();
Ganti628->addOutput(Ganti);
FuzzyRule* fuzzyRule628 = new FuzzyRule(628, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah628, Ganti628);
fuzzy->addFuzzyRule(fuzzyRule628);
// 629 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal629 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal629->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak629 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak629->joinWithAND(DO_Banyak_pH_Normal629, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah629 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah629->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak629, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam629 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam629->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah629, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal629 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal629->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam629, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti629 = new FuzzyRuleConsequent();
Ganti629->addOutput(Ganti);
FuzzyRule* fuzzyRule629 = new FuzzyRule(629, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal629, Ganti629);
fuzzy->addFuzzyRule(fuzzyRule629);
// 630 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal630 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal630->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak630 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak630->joinWithAND(DO_Banyak_pH_Normal630, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah630 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah630->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak630, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam630 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam630->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah630, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi630 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi630->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam630, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti630 = new FuzzyRuleConsequent();
Ganti630->addOutput(Ganti);
FuzzyRule* fuzzyRule630 = new FuzzyRule(630, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi630, Ganti630);
fuzzy->addFuzzyRule(fuzzyRule630);
// 631 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal631 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal631->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak631 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak631->joinWithAND(DO_Banyak_pH_Normal631, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal631 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal631->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak631, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal631 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal631->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal631, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah631 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah631->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal631, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti631 = new FuzzyRuleConsequent();
Ganti631->addOutput(Ganti);
FuzzyRule* fuzzyRule631 = new FuzzyRule(631, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah631, Ganti631);
fuzzy->addFuzzyRule(fuzzyRule631);
// 632 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal632 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal632->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak632 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak632->joinWithAND(DO_Banyak_pH_Normal632, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal632 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal632->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak632, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal632 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal632->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal632, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal632 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal632->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal632, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti632 = new FuzzyRuleConsequent();
Ganti632->addOutput(Ganti);
FuzzyRule* fuzzyRule632 = new FuzzyRule(632, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal632, Ganti632);
fuzzy->addFuzzyRule(fuzzyRule632);
// 633 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal633 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal633->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak633 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak633->joinWithAND(DO_Banyak_pH_Normal633, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal633 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal633->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak633, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal633 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal633->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal633, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi633 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi633->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal633, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti633 = new FuzzyRuleConsequent();
Ganti633->addOutput(Ganti);
FuzzyRule* fuzzyRule633 = new FuzzyRule(633, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi633, Ganti633);
fuzzy->addFuzzyRule(fuzzyRule633);
// 634 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal634 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal634->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak634 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak634->joinWithAND(DO_Banyak_pH_Normal634, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal634 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal634->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak634, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang634 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang634->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal634, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah634 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah634->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang634, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti634 = new FuzzyRuleConsequent();
Ganti634->addOutput(Ganti);
FuzzyRule* fuzzyRule634 = new FuzzyRule(634, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah634, Ganti634);
fuzzy->addFuzzyRule(fuzzyRule634);
// 635 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal635 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal635->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak635 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak635->joinWithAND(DO_Banyak_pH_Normal635, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal635 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal635->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak635, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang635 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang635->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal635, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal635 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal635->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang635, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti635 = new FuzzyRuleConsequent();
Ganti635->addOutput(Ganti);
FuzzyRule* fuzzyRule635 = new FuzzyRule(635, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Normal635, Ganti635);
fuzzy->addFuzzyRule(fuzzyRule635);
// 636 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal636 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal636->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak636 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak636->joinWithAND(DO_Banyak_pH_Normal636, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal636 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal636->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak636, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang636 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang636->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal636, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi636 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi636->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang636, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti636 = new FuzzyRuleConsequent();
Ganti636->addOutput(Ganti);
FuzzyRule* fuzzyRule636 = new FuzzyRule(636, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi636, Ganti636);
fuzzy->addFuzzyRule(fuzzyRule636);
// 637 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal637 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal637->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak637 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak637->joinWithAND(DO_Banyak_pH_Normal637, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal637 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal637->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak637, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam637 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam637->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal637, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah637 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah637->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam637, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti637 = new FuzzyRuleConsequent();
Ganti637->addOutput(Ganti);
FuzzyRule* fuzzyRule637 = new FuzzyRule(637, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Rendah637, Ganti637);
fuzzy->addFuzzyRule(fuzzyRule637);
// 638 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal638 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal638->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak638 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak638->joinWithAND(DO_Banyak_pH_Normal638, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal638 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal638->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak638, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam638 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam638->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal638, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal638 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal638->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam638, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti638 = new FuzzyRuleConsequent();
Ganti638->addOutput(Ganti);
FuzzyRule* fuzzyRule638 = new FuzzyRule(638, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Normal638, Ganti638);
fuzzy->addFuzzyRule(fuzzyRule638);
// 639 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal639 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal639->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak639 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak639->joinWithAND(DO_Banyak_pH_Normal639, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal639 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal639->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak639, Kekeruhan_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam639 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam639->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal639, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi639 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi639->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam639, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti639 = new FuzzyRuleConsequent();
Ganti639->addOutput(Ganti);
FuzzyRule* fuzzyRule639 = new FuzzyRule(639, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi639, Ganti639);
fuzzy->addFuzzyRule(fuzzyRule639);
// 640 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal640 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal640->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak640 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak640->joinWithAND(DO_Banyak_pH_Normal640, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak640 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak640->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak640, Kekeruhan_Banyak); // Mengubah Kekeruhan_Normal menjadi Kekeruhan_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal640 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal640->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak640, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah640 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah640->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal640, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti640 = new FuzzyRuleConsequent();
Ganti640->addOutput(Ganti);
FuzzyRule* fuzzyRule640 = new FuzzyRule(640, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Rendah640, Ganti640);
fuzzy->addFuzzyRule(fuzzyRule640);
// 641 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal641 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal641->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak641 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak641->joinWithAND(DO_Banyak_pH_Normal641, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak641 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak641->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak641, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal641 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal641->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak641, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal641 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal641->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal641, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti641 = new FuzzyRuleConsequent();
Ganti641->addOutput(Ganti);
FuzzyRule* fuzzyRule641 = new FuzzyRule(641, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Normal641, Ganti641);
fuzzy->addFuzzyRule(fuzzyRule641);
// 642 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal642 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal642->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak642 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak642->joinWithAND(DO_Banyak_pH_Normal642, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak642 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak642->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak642, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal642 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal642->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak642, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi642 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi642->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal642, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti642 = new FuzzyRuleConsequent();
Ganti642->addOutput(Ganti);
FuzzyRule* fuzzyRule642 = new FuzzyRule(642, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dangkal_EC_Tinggi642, Ganti642);
fuzzy->addFuzzyRule(fuzzyRule642);
// 643 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal643 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal643->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak643 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak643->joinWithAND(DO_Banyak_pH_Normal643, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak643 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak643->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak643, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang643 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang643->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak643, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah643 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah643->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang643, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti643 = new FuzzyRuleConsequent();
Ganti643->addOutput(Ganti);
FuzzyRule* fuzzyRule643 = new FuzzyRule(643, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Rendah643, Ganti643);
fuzzy->addFuzzyRule(fuzzyRule643);
// 644 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal644 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal644->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak644 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak644->joinWithAND(DO_Banyak_pH_Normal644, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak644 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak644->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak644, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang644 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang644->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak644, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal644 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal644->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang644, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti644 = new FuzzyRuleConsequent();
Ganti644->addOutput(Ganti);
FuzzyRule* fuzzyRule644 = new FuzzyRule(644, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Normal644, Ganti644);
fuzzy->addFuzzyRule(fuzzyRule644);
// 645 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal645 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal645->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak645 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak645->joinWithAND(DO_Banyak_pH_Normal645, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak645 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak645->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak645, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang645 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang645->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak645, Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi645 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi645->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang645, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti645 = new FuzzyRuleConsequent();
Ganti645->addOutput(Ganti);
FuzzyRule* fuzzyRule645 = new FuzzyRule(645, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Sedang_EC_Tinggi645, Ganti645);
fuzzy->addFuzzyRule(fuzzyRule645);
// 646 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal646 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal646->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak646 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak646->joinWithAND(DO_Banyak_pH_Normal646, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak646 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak646->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak646, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam646 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam646->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak646, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah646 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah646->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam646, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti646 = new FuzzyRuleConsequent();
Ganti646->addOutput(Ganti);
FuzzyRule* fuzzyRule646 = new FuzzyRule(646, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Rendah646, Ganti646);
fuzzy->addFuzzyRule(fuzzyRule646);
// 647 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal647 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal647->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak647 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak647->joinWithAND(DO_Banyak_pH_Normal647, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak647 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak647->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak647, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam647 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam647->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak647, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal647 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal647->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam647, EC_Normal); // Mengubah EC_Rendah menjadi EC_Normal
FuzzyRuleConsequent* Ganti647 = new FuzzyRuleConsequent();
Ganti647->addOutput(Ganti);
FuzzyRule* fuzzyRule647 = new FuzzyRule(647, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Normal647, Ganti647);
fuzzy->addFuzzyRule(fuzzyRule647);
// 648 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Normal648 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal648->joinWithAND(DO_Banyak, pH_Normal);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak648 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak648->joinWithAND(DO_Banyak_pH_Normal648, Suhu_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak648 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak648->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak648, Kekeruhan_Banyak);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam648 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam648->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak648, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi648 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi648->joinWithAND(DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam648, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti648 = new FuzzyRuleConsequent();
Ganti648->addOutput(Ganti);
FuzzyRule* fuzzyRule648 = new FuzzyRule(648, DO_Banyak_pH_Normal_Suhu_Banyak_Kekeruhan_Banyak_Jarak_Dalam_EC_Tinggi648, Ganti648);
fuzzy->addFuzzyRule(fuzzyRule648);
// 649 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak649 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak649->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah649 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah649->joinWithAND(DO_Banyak_pH_Banyak649, Suhu_Rendah); // Mengubah Suhu_Banyak menjadi Suhu_Rendah
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah649 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah649->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah649, Kekeruhan_Rendah); // Mengubah Kekeruhan_Banyak menjadi Kekeruhan_Rendah
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal649 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal649->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah649, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah649 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah649->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal649, EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti649 = new FuzzyRuleConsequent();
Ganti649->addOutput(Ganti);
FuzzyRule* fuzzyRule649 = new FuzzyRule(649, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah649, Ganti649);
fuzzy->addFuzzyRule(fuzzyRule649);
// 650 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak650 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak650->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah650 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah650->joinWithAND(DO_Banyak_pH_Banyak650, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah650 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah650->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah650, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal650 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal650->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah650, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal650 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal650->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal650, EC_Normal); 
FuzzyRuleConsequent* Ganti650 = new FuzzyRuleConsequent();
Ganti650->addOutput(Ganti);
FuzzyRule* fuzzyRule650 = new FuzzyRule(650, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal650, Ganti650);
fuzzy->addFuzzyRule(fuzzyRule650);
// 651 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak651 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak651->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah651 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah651->joinWithAND(DO_Banyak_pH_Banyak651, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah651 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah651->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah651, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal651 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal651->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah651, Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi651 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi651->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal651, EC_Tinggi); // Mengubah EC_Normal menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti651 = new FuzzyRuleConsequent();
Ganti651->addOutput(Ganti);
FuzzyRule* fuzzyRule651 = new FuzzyRule(651, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Tinggi651, Ganti651);
fuzzy->addFuzzyRule(fuzzyRule651);
// 652 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak652=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak652->joinWithAND(DO_Banyak,pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah652=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah652->joinWithAND(DO_Banyak_pH_Banyak652,Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah652=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah652->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah652,Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal652=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal652->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah652,Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah652=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah652->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal652,EC_Rendah); // Mengubah EC_Normal menjadi EC_Rendah
FuzzyRuleConsequent* Ganti652=new FuzzyRuleConsequent();
Ganti652->addOutput(Ganti);
FuzzyRule* fuzzyRule652=new FuzzyRule(652,DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Rendah652,Ganti652);
fuzzy->addFuzzyRule(fuzzyRule652);
// 653 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak653=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak653->joinWithAND(DO_Banyak,pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah653=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah653->joinWithAND(DO_Banyak_pH_Banyak653,Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah653=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah653->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah653,Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal653=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal653->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah653,Jarak_Dangkal);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal653=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal653->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal653,EC_Normal); // Mengubah EC_Tinggi menjadi EC_Normal
FuzzyRuleConsequent* Ganti653=new FuzzyRuleConsequent();
Ganti653->addOutput(Ganti);
FuzzyRule* fuzzyRule653=new FuzzyRule(653,DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dangkal_EC_Normal653,Ganti653);
fuzzy->addFuzzyRule(fuzzyRule653);
// 654 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak654=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak654->joinWithAND(DO_Banyak,pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah654=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah654->joinWithAND(DO_Banyak_pH_Banyak654,Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah654=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah654->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah654,Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang654=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang654->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah654,Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi654=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi654->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang654,EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti654=new FuzzyRuleConsequent();
Ganti654->addOutput(Ganti);
FuzzyRule* fuzzyRule654=new FuzzyRule(654,DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Tinggi654,Ganti654);
fuzzy->addFuzzyRule(fuzzyRule654);
// 655 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak655=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak655->joinWithAND(DO_Banyak,pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah655=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah655->joinWithAND(DO_Banyak_pH_Banyak655,Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah655=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah655->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah655,Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang655=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang655->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah655,Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah655=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah655->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang655,EC_Rendah); // Mengubah EC_Tinggi menjadi EC_Rendah
FuzzyRuleConsequent* Ganti655=new FuzzyRuleConsequent();
Ganti655->addOutput(Ganti);
FuzzyRule* fuzzyRule655=new FuzzyRule(655,DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Rendah655,Ganti655);
fuzzy->addFuzzyRule(fuzzyRule655);
// 656 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak656=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak656->joinWithAND(DO_Banyak,pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah656=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah656->joinWithAND(DO_Banyak_pH_Banyak656,Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah656=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah656->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah656,Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang656=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang656->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah656,Jarak_Sedang);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal656=new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal656->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang656,EC_Normal); // Mengubah EC_Tinggi menjadi EC_Normal
FuzzyRuleConsequent* Ganti656=new FuzzyRuleConsequent();
Ganti656->addOutput(Ganti);
FuzzyRule* fuzzyRule656=new FuzzyRule(656,DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Sedang_EC_Normal656,Ganti656);
fuzzy->addFuzzyRule(fuzzyRule656);
// 657 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak657 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak657->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah657 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah657->joinWithAND(DO_Banyak_pH_Banyak657, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah657 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah657->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah657, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam657 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam657->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah657, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi657 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi657->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam657, EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti657 = new FuzzyRuleConsequent();
Ganti657->addOutput(Ganti);
FuzzyRule* fuzzyRule657 = new FuzzyRule(657, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Tinggi657, Ganti657);
fuzzy->addFuzzyRule(fuzzyRule657);
// 658 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak658 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak658->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah658 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah658->joinWithAND(DO_Banyak_pH_Banyak658, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah658 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah658->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah658, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam658 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam658->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah658, Jarak_Dalam);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah658 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah658->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam658, EC_Rendah); // Mengubah EC_Normal menjadi EC_Rendah
FuzzyRuleConsequent* Ganti658 = new FuzzyRuleConsequent();
Ganti658->addOutput(Ganti);
FuzzyRule* fuzzyRule658 = new FuzzyRule(658, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Rendah658, Ganti658);
fuzzy->addFuzzyRule(fuzzyRule658);
// 659 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak659 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak659->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah659 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah659->joinWithAND(DO_Banyak_pH_Banyak659, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah659 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah659->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah659, Kekeruhan_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam659 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam659->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah659, Jarak_Dalam); // Mengubah Jarak_Tinggi menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal659 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal659->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam659, EC_Normal); // Mengubah EC_Tinggi menjadi EC_Normal
FuzzyRuleConsequent* Ganti659 = new FuzzyRuleConsequent();
Ganti659->addOutput(Ganti);
FuzzyRule* fuzzyRule659 = new FuzzyRule(659, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Rendah_Jarak_Dalam_EC_Normal659, Ganti659);
fuzzy->addFuzzyRule(fuzzyRule659);
// 660 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak660 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak660->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah660 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah660->joinWithAND(DO_Banyak_pH_Banyak660, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal660 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal660->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah660, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal660 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal660->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal660, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi660 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi660->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal660, EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti660 = new FuzzyRuleConsequent();
Ganti660->addOutput(Ganti);
FuzzyRule* fuzzyRule660 = new FuzzyRule(660, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Tinggi660, Ganti660);
fuzzy->addFuzzyRule(fuzzyRule660);
// 661 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak661 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak661->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah661 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah661->joinWithAND(DO_Banyak_pH_Banyak661, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal661 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal661->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah661, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal661 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal661->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal661, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah661 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah661->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal661, EC_Rendah); // Mengubah EC_Normal menjadi EC_Rendah
FuzzyRuleConsequent* Ganti661 = new FuzzyRuleConsequent();
Ganti661->addOutput(Ganti);
FuzzyRule* fuzzyRule661 = new FuzzyRule(661, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Rendah661, Ganti661);
fuzzy->addFuzzyRule(fuzzyRule661);
// 662 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak662 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak662->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah662 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah662->joinWithAND(DO_Banyak_pH_Banyak662, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal662 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal662->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah662, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal662 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal662->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal662, Jarak_Dangkal); // Mengubah Jarak_Dalam menjadi Jarak_Dangkal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal662 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal662->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal662, EC_Normal); // Mengubah EC_Tinggi menjadi EC_Normal
FuzzyRuleConsequent* Ganti662 = new FuzzyRuleConsequent();
Ganti662->addOutput(Ganti);
FuzzyRule* fuzzyRule662 = new FuzzyRule(662, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dangkal_EC_Normal662, Ganti662);
fuzzy->addFuzzyRule(fuzzyRule662);
// 663 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak663 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak663->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah663 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah663->joinWithAND(DO_Banyak_pH_Banyak663, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal663 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal663->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah663, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang663 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang663->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal663, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi663 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi663->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang663, EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti663 = new FuzzyRuleConsequent();
Ganti663->addOutput(Ganti);
FuzzyRule* fuzzyRule663 = new FuzzyRule(663, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Tinggi663, Ganti663);
fuzzy->addFuzzyRule(fuzzyRule663);
// 664 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak664 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak664->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah664 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah664->joinWithAND(DO_Banyak_pH_Banyak664, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal664 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal664->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah664, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang664 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang664->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal664, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah664 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah664->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang664, EC_Rendah); // Mengubah EC_Normal menjadi EC_Rendah
FuzzyRuleConsequent* Ganti664 = new FuzzyRuleConsequent();
Ganti664->addOutput(Ganti);
FuzzyRule* fuzzyRule664 = new FuzzyRule(664, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Rendah664, Ganti664);
fuzzy->addFuzzyRule(fuzzyRule664);
// 665 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak665 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak665->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah665 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah665->joinWithAND(DO_Banyak_pH_Banyak665, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal665 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal665->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah665, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang665 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang665->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal665, Jarak_Sedang); // Mengubah Jarak_Dangkal menjadi Jarak_Sedang
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal665 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal665->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang665, EC_Normal); // Mengubah EC_Tinggi menjadi EC_Normal
FuzzyRuleConsequent* Ganti665 = new FuzzyRuleConsequent();
Ganti665->addOutput(Ganti);
FuzzyRule* fuzzyRule665 = new FuzzyRule(665, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Sedang_EC_Normal665, Ganti665);
fuzzy->addFuzzyRule(fuzzyRule665);
// 666 (perubahan)
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak666 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak666->joinWithAND(DO_Banyak, pH_Banyak); // Mengubah pH_Normal menjadi pH_Banyak
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah666 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah666->joinWithAND(DO_Banyak_pH_Banyak666, Suhu_Rendah);
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal666 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal666->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah666, Kekeruhan_Normal); // Mengubah Kekeruhan_Rendah menjadi Kekeruhan_Normal
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam666 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam666->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal666, Jarak_Dalam); // Mengubah Jarak_Sedang menjadi Jarak_Dalam
FuzzyRuleAntecedent* DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi666 = new FuzzyRuleAntecedent();
DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi666->joinWithAND(DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam666, EC_Tinggi); // Mengubah EC_Rendah menjadi EC_Tinggi
FuzzyRuleConsequent* Ganti666 = new FuzzyRuleConsequent();
Ganti666->addOutput(Ganti);
FuzzyRule* fuzzyRule666 = new FuzzyRule(666, DO_Banyak_pH_Banyak_Suhu_Rendah_Kekeruhan_Normal_Jarak_Dalam_EC_Tinggi666, Ganti666);
fuzzy->addFuzzyRule(fuzzyRule666);


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