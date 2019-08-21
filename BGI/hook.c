//1342D20
//1342D0A
//432D05
//432D20

int __usercall sub_432D20@<eax>(int a1@<edx>, _DWORD *a2@<ecx>, int a3, _BYTE *a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
  int v13; // edi@1
  int result; // eax@1
  char v15; // al@2
  void *v16; // ecx@2
  signed int v17; // ecx@2
  const char *v18; // edx@6
  int v19; // eax@13
  int v20; // esi@13
  unsigned int v21; // edx@16
  int v22; // ecx@16
  int v23; // eax@18
  int v24; // edx@20
  int v25; // ebx@25
  int v26; // eax@25
  unsigned int v27; // kr00_4@25
  int v28; // esi@25
  int v29; // ecx@28
  unsigned int v30; // edx@32
  unsigned __int8 v31; // cl@34
  int v32; // eax@37
  int v33; // eax@40
  int v34; // ecx@40
  _DWORD *v35; // edx@40
  unsigned int v36; // ecx@42
  bool v37; // zf@42
  int v38; // edi@43
  unsigned __int8 v39; // al@43
  int v40; // edx@43
  int v41; // eax@45
  unsigned int v42; // esi@48
  char v43; // al@49
  int v44; // eax@53
  int v45; // ebx@54
  int v46; // ecx@55
  const char *v47; // esi@55
  unsigned int v48; // ecx@56
  char *v49; // eax@56
  bool v50; // cf@57
  char v51; // dl@59
  int v52; // eax@61
  const char *v53; // edx@65
  char *v54; // esi@65
  signed int v55; // eax@69
  int v56; // eax@76
  const char *v57; // eax@81
  int v58; // edx@81
  char *v59; // edi@83
  void (__stdcall ***v60)(_DWORD); // esi@87
  void (__stdcall ***v61)(_DWORD); // esi@104
  char *v62; // ecx@135
  char *v63; // ebx@135
  int v64; // eax@137
  int i; // eax@140
  char *v66; // edi@143
  int v67; // eax@144
  int v68; // esi@146
  int v69; // ST10_4@148
  char *v70; // ebx@151
  int v71; // eax@152
  int v72; // esi@154
  void *v73; // ecx@157
  char v74; // bl@157
  char *v75; // edi@158
  int v76; // eax@159
  int v77; // esi@161
  char *v78; // ebx@162
  int v79; // ebx@170
  unsigned int v80; // esi@170
  char *v81; // eax@171
  int v82; // edi@174
  void *v83; // esi@174
  int v84; // eax@174
  int v85; // edx@180
  int v86; // ebx@180
  int v87; // edi@180
  void *v88; // esi@180
  void *v89; // ST1C_4@182
  CHAR *v90; // edi@186
  int v91; // ebx@191
  int v92; // eax@196
  unsigned int v93; // esi@202
  size_t v94; // eax@205
  int v95; // ST1C_4@207
  int v96; // ST18_4@207
  char *j; // ebx@215
  int v98; // ecx@217
  int v99; // edi@218
  char v100; // al@219
  int v101; // eax@226
  const char *v102; // ebx@226
  int v103; // ecx@228
  unsigned int v104; // esi@228
  int v105; // eax@229
  void *v106; // edi@231
  const char *v107; // edx@231
  int v108; // eax@240
  unsigned int v109; // edx@241
  const char *v110; // edi@241
  int v111; // edx@251
  int v112; // eax@252
  int v113; // ebx@252
  int v114; // esi@252
  int v115; // ecx@252
  void *v116; // esi@254
  int v117; // ecx@254
  int v118; // ecx@254
  int v119; // ecx@254
  int v120; // edx@254
  int v121; // eax@254
  int v122; // ecx@254
  int v123; // edx@254
  int v124; // ecx@257
  int v125; // esi@266
  int v126; // ecx@266
  int v127; // edi@266
  void *v128; // eax@267
  void *v129; // eax@273
  _DWORD *v130; // ebx@279
  int v131; // eax@279
  int v132; // ecx@279
  int v133; // ecx@282
  int v134; // esi@282
  int v135; // ecx@285
  int v136; // esi@285
  void *v137; // esi@287
  char *v138; // edi@289
  _BYTE *v139; // esi@289
  void *v140; // eax@289
  char *v141; // eax@289
  int v142; // ecx@289
  int v143; // eax@289
  int v144; // edi@289
  int v145; // eax@303
  char *v146; // ecx@303
  _BYTE *v147; // edx@303
  char v148; // al@304
  int v149; // eax@305
  int v150; // edi@305
  int v151; // ecx@309
  int v152; // edi@309
  int v153; // ecx@310
  int v154; // ecx@311
  int v155; // eax@316
  int v156; // edx@316
  char v157; // cl@316
  int v158; // edi@321
  int v159; // ecx@325
  _DWORD *v160; // eax@325
  int v161; // eax@327
  int v162; // edx@327
  int v163; // eax@327
  int v164; // eax@327
  int v165; // edx@327
  void *v166; // [sp+14h] [bp-940h]@32
  void *v167; // [sp+18h] [bp-93Ch]@55
  void *v168; // [sp+1Ch] [bp-938h]@2
  CHAR *v169; // [sp+20h] [bp-934h]@42
  int v170; // [sp+24h] [bp-930h]@32
  unsigned int v171; // [sp+28h] [bp-92Ch]@42
  int v172; // [sp+2Ch] [bp-928h]@2
  _BYTE *v173; // [sp+30h] [bp-924h]@1
  int v174; // [sp+34h] [bp-920h]@52
  int v175; // [sp+38h] [bp-91Ch]@252
  int v176; // [sp+3Ch] [bp-918h]@42
  void *v177; // [sp+40h] [bp-914h]@42
  void *v178; // [sp+44h] [bp-910h]@86
  char *v179; // [sp+48h] [bp-90Ch]@252
  int v180; // [sp+4Ch] [bp-908h]@1
  int v181; // [sp+54h] [bp-900h]@92
  int v182; // [sp+58h] [bp-8FCh]@42
  int v183; // [sp+5Ch] [bp-8F8h]@13
  char *v184; // [sp+60h] [bp-8F4h]@25
  int v185; // [sp+64h] [bp-8F0h]@20
  int v186; // [sp+68h] [bp-8ECh]@42
  int v187; // [sp+6Ch] [bp-8E8h]@20
  int v188; // [sp+70h] [bp-8E4h]@16
  _BYTE *v189; // [sp+74h] [bp-8E0h]@42
  int v190; // [sp+78h] [bp-8DCh]@18
  int v191; // [sp+7Ch] [bp-8D8h]@42
  void *v192; // [sp+80h] [bp-8D4h]@252
  int v193; // [sp+84h] [bp-8D0h]@1
  int v194; // [sp+88h] [bp-8CCh]@1
  _DWORD *v195; // [sp+8Ch] [bp-8C8h]@1
  int v196; // [sp+90h] [bp-8C4h]@42
  int v197; // [sp+94h] [bp-8C0h]@42
  int v198; // [sp+98h] [bp-8BCh]@254
  int v199; // [sp+9Ch] [bp-8B8h]@254
  int v200; // [sp+A0h] [bp-8B4h]@254
  int v201; // [sp+A4h] [bp-8B0h]@254
  int v202; // [sp+A8h] [bp-8ACh]@254
  int v203; // [sp+ACh] [bp-8A8h]@254
  int v204; // [sp+B0h] [bp-8A4h]@25
  int v205; // [sp+B4h] [bp-8A0h]@25
  int v206; // [sp+B8h] [bp-89Ch]@42
  int v207; // [sp+BCh] [bp-898h]@1
  int v208; // [sp+C0h] [bp-894h]@14
  signed int v209; // [sp+C4h] [bp-890h]@2
  int v210; // [sp+C8h] [bp-88Ch]@25
  int v211; // [sp+CCh] [bp-888h]@282
  int v212; // [sp+D0h] [bp-884h]@282
  int v213; // [sp+D4h] [bp-880h]@282
  int v214; // [sp+D8h] [bp-87Ch]@282
  int v215; // [sp+DCh] [bp-878h]@282
  int v216; // [sp+E0h] [bp-874h]@282
  int v217; // [sp+E4h] [bp-870h]@180
  int v218; // [sp+E8h] [bp-86Ch]@180
  char *v219; // [sp+ECh] [bp-868h]@289
  char *v220; // [sp+F0h] [bp-864h]@289
  int v221; // [sp+F4h] [bp-860h]@1
  int v222; // [sp+F8h] [bp-85Ch]@2
  int v223; // [sp+FCh] [bp-858h]@259
  int v224; // [sp+100h] [bp-854h]@264
  int v225; // [sp+104h] [bp-850h]@260
  int v226; // [sp+108h] [bp-84Ch]@264
  char *v227; // [sp+10Ch] [bp-848h]@37
  int v228; // [sp+110h] [bp-844h]@303
  int v229; // [sp+118h] [bp-83Ch]@256
  int v230; // [sp+11Ch] [bp-838h]@256
  int v231; // [sp+120h] [bp-834h]@256
  int v232; // [sp+124h] [bp-830h]@256
  int v233; // [sp+128h] [bp-82Ch]@256
  int v234; // [sp+12Ch] [bp-828h]@256
  int v235; // [sp+130h] [bp-824h]@282
  int v236; // [sp+134h] [bp-820h]@282
  int v237; // [sp+138h] [bp-81Ch]@282
  int v238; // [sp+13Ch] [bp-818h]@282
  int v239; // [sp+140h] [bp-814h]@282
  int v240; // [sp+144h] [bp-810h]@282
  int v241; // [sp+148h] [bp-80Ch]@89
  const char *v242; // [sp+158h] [bp-7FCh]@55
  const char *v243; // [sp+15Ch] [bp-7F8h]@55
  const char *v244; // [sp+160h] [bp-7F4h]@55
  const char *v245; // [sp+164h] [bp-7F0h]@55
  const char *v246; // [sp+168h] [bp-7ECh]@55
  const char *v247; // [sp+16Ch] [bp-7E8h]@55
  const char *v248; // [sp+170h] [bp-7E4h]@55
  const char *v249; // [sp+174h] [bp-7E0h]@55
  const char *v250; // [sp+178h] [bp-7DCh]@55
  const char *v251; // [sp+17Ch] [bp-7D8h]@55
  const char *v252; // [sp+180h] [bp-7D4h]@55
  const char *v253; // [sp+184h] [bp-7D0h]@55
  const char *v254; // [sp+188h] [bp-7CCh]@55
  const char *v255; // [sp+18Ch] [bp-7C8h]@55
  int v256; // [sp+190h] [bp-7C4h]@55
  int v257; // [sp+1A8h] [bp-7ACh]@266
  int v258; // [sp+1B0h] [bp-7A4h]@319
  void *v259; // [sp+1BCh] [bp-798h]@293
  int v260; // [sp+1C8h] [bp-78Ch]@310
  CHAR pszFaceName; // [sp+1D4h] [bp-780h]@42
  int v262; // [sp+1F4h] [bp-760h]@89
  int v263; // [sp+1F8h] [bp-75Ch]@89
  int v264; // [sp+1FCh] [bp-758h]@85
  DWORD bItalic; // [sp+200h] [bp-754h]@89
  void (__stdcall ***v266)(_DWORD); // [sp+204h] [bp-750h]@42
  char v267; // [sp+208h] [bp-74Ch]@37
  int v268; // [sp+228h] [bp-72Ch]@13
  int v269; // [sp+22Ch] [bp-728h]@98
  int v270; // [sp+230h] [bp-724h]@124
  int v271; // [sp+234h] [bp-720h]@99
  int v272; // [sp+238h] [bp-71Ch]@25
  char v273[256]; // [sp+23Ch] [bp-718h]@55
  char v274; // [sp+33Ch] [bp-618h]@135
  char v275; // [sp+43Ch] [bp-518h]@135
  char v276; // [sp+53Ch] [bp-418h]@300
  char v277; // [sp+53Dh] [bp-417h]@317
  char v278; // [sp+53Eh] [bp-416h]@317
  int v279; // [sp+950h] [bp-4h]@86

  v13 = (int)a4;
  v194 = a3;
  v195 = a2;
  v180 = a6;
  v207 = a1;
  v173 = a4;
  v193 = a13;
  result = sub_408A20(dword_54A438);
  v221 = result;
  if ( !result )
    return result;
  sub_435790();
  v222 = sub_4359C0();
  v15 = *a4;
  v209 = (signed int)v16;
  v172 = (int)v16;
  v168 = v16;
  v17 = 1;
  if ( v15 < 32 )
  {
    switch ( v15 )
    {
      case 2:
        v209 = 1;
        v13 = (int)(a4 + 1);
        goto LABEL_12;
      case 3:
        v172 = 1;
        v13 = (int)(a4 + 1);
        goto LABEL_12;
      case 4:
        v18 = "「";
        goto LABEL_11;
      case 5:
        v18 = "　";
        goto LABEL_11;
      case 6:
        v18 = "（";
        goto LABEL_11;
      case 7:
        v18 = "“";
        goto LABEL_11;
      case 8:
        v18 = "『";
LABEL_11:
        v168 = (void *)1;
        sub_42BB00(1, v18);
        v13 = (int)(a4 + 1);
LABEL_12:
        v173 = (_BYTE *)v13;
        break;
      default:
        break;
    }
  }
  v19 = sub_434A00(v17);
  v20 = v268;
  v183 = v19;
  if ( a5 )
    v208 = sub_434A20(v268);
  else
    v208 = 0;
  v21 = (signed int)((unsigned __int64)(1374389535i64 * v20 * *(_DWORD *)(a13 + 4)) >> 32) >> 5;
  v22 = v21 + (v21 >> 31);
  v188 = v22;
  if ( v22 <= 0 )
  {
    v22 = 1;
    v188 = 1;
  }
  v23 = v20 * *(_DWORD *)(a13 + 8) / 100;
  v190 = v23;
  if ( v23 <= 0 )
  {
    v23 = 1;
    v190 = 1;
  }
  v185 = 0;
  v187 = 0;
  v24 = *(_DWORD *)a13 - 1;
  if ( *(_DWORD *)a13 == 1 )
  {
    v185 = v22;
    goto LABEL_24;
  }
  v24 = *(_DWORD *)a13 - 2;
  if ( *(_DWORD *)a13 == 2 )
  {
    v24 = 2 * v22;
    v185 = 2 * v22;
    v23 *= 2;
LABEL_24:
    v187 = v23;
  }
  v25 = v272;
  v26 = sub_42BA60(v22, v24);
  sub_42BA70(v26);
  sub_4087F0(1);
  v27 = strlen((const char *)v13);
  v28 = 0;
  v205 = unknown_libname_10(v27 + 1);
  v184 = 0;
  v210 = 0;
  v204 = 0;
  if ( a11 )
  {
    v210 = v268;
    if ( dword_54A5B8 )
    {
      if ( !v172 )
      {
        if ( sub_435410(v268, v13) )
        {
          if ( !v168 )
          {
            if ( sub_42BB00(v29, v13) )
            {
              v31 = *(_BYTE *)(v13 + 1);
              LOBYTE(v170) = *(_BYTE *)v13;
              *(_WORD *)((char *)&v170 + 1) = v31;
LABEL_37:
              sub_432990(&v227, &v170, &v267, a10);
              v32 = sub_434970(a10);
              v28 = (int)&v227[v32];
              v184 = &v227[v32];
              goto LABEL_38;
            }
            LOBYTE(v30) = *(_BYTE *)v13;
            BYTE1(v170) = 0;
LABEL_36:
            LOBYTE(v170) = v30;
            goto LABEL_37;
          }
        }
        else if ( !v168 )
        {
          goto LABEL_38;
        }
        v30 = (unsigned int)v166 >> 8;
        *(_WORD *)((char *)&v170 + 1) = (unsigned __int8)v166;
        goto LABEL_36;
      }
    }
  }
LABEL_38:
  if ( a5 )
  {
    if ( *(_DWORD *)v180 == *(_DWORD *)a7 )
    {
      v33 = sub_431F60();
      *v35 = v34 + v33;
    }
    v184 = (char *)(sub_431F60() + v28);
  }
  qmemcpy(&pszFaceName, &v267, 0x34u);
  v182 = 0;
  v197 = 0;
  v196 = 0;
  v171 = 0;
  v191 = 0;
  v206 = 0;
  v186 = 1;
  v169 = &v267;
  sub_42BA90(v25);
  v266 = 0;
  sub_42BAC0(v25);
  sub_42BAC0(v25);
  v36 = (unsigned int)v173;
  *v195 = 1;
  v37 = *(_BYTE *)v36 == 0;
  v176 = 0;
  v168 = 0;
  v177 = 0;
  v189 = 0;
  if ( v37 )
    goto LABEL_329;
  do
  {
    v38 = v171;
    v39 = v173[v171];
    v40 = (int)&v173[v171];
    v166 = &v173[v171];
    if ( v39 < 0x20u )
    {
      if ( v39 == 10 )
      {
        v36 = (unsigned int)&v184[*(_DWORD *)a7];
        v41 = v180;
        *(_DWORD *)(v41 + 4) += a8;
        *(_DWORD *)v41 = v36;
        ++*v195;
        v186 = 1;
      }
      v171 = v38 + 1;
      continue;
    }
    if ( v39 != 60 )
      goto LABEL_225;
    v36 = (unsigned int)&v173[v171 + 1];
    v42 = 1;
    if ( !*(_BYTE *)v36 )
      goto LABEL_225;
    v43 = *(_BYTE *)(v40 + 1);
    do
    {
      if ( v43 == 62 )
        break;
      v43 = *(_BYTE *)(v40 + v42++ + 1);
    }
    while ( v43 );
    v174 = v42;
    if ( v42 <= 1 )
      goto LABEL_225;
    v44 = (int)(&v173[v42] + v171);
    if ( *(_BYTE *)v44 != 62 )
      goto LABEL_225;
    v45 = 0;
    if ( v206 )
    {
      v206 = 0;
LABEL_225:
      if ( a11 )
      {
        v101 = sub_42BB00(v36, v40);
        v102 = "　";
        if ( !v101 )
          v102 = " ";
        v103 = v101 != 0;
        v104 = v103 + 1;
        if ( v101 )
          v105 = sub_434A00(v103);
        else
          v105 = sub_434A00(v103) >> 1;
        v106 = v166;
        v172 = v105;
        v36 = v104;
        v107 = v102;
        if ( v104 < 4 )
        {
LABEL_234:
          if ( !v36
            || *v107 == *(_BYTE *)v106
            && (v36 <= 1
             || v107[1] == *((_BYTE *)v106 + 1)
             && (v36 <= 2 || (LOBYTE(v36) = v107[2], (_BYTE)v36 == *((_BYTE *)v106 + 2)))) )
          {
            v108 = v171;
            if ( v171 >= v104 )
            {
              v36 = (unsigned int)(&v173[v171] - v104);
              v109 = v104;
              v110 = v102;
              if ( v104 < 4 )
              {
LABEL_244:
                if ( !v109
                  || *v110 == *(_BYTE *)v36
                  && (v109 <= 1 || v110[1] == *(_BYTE *)(v36 + 1) && (v109 <= 2 || v110[2] == *(_BYTE *)(v36 + 2))) )
                {
                  goto LABEL_252;
                }
              }
              else
              {
                while ( *(_DWORD *)v36 == *(_DWORD *)v110 )
                {
                  v109 -= 4;
                  v110 += 4;
                  v36 += 4;
                  if ( v109 < 4 )
                    goto LABEL_244;
                }
              }
              v36 = v180;
              if ( v172 + *(_DWORD *)v180 > *(_DWORD *)(a7 + 8) - v268 + 1 )
              {
                v111 = (int)&v184[*(_DWORD *)a7];
                v186 = 1;
                *(_DWORD *)v180 = v111;
                *(_DWORD *)(v36 + 4) += a8;
                v36 = (unsigned int)v195;
                ++*(_DWORD *)v36;
                v171 = v104 + v108;
                continue;
              }
            }
          }
        }
        else
        {
          while ( *(_DWORD *)v106 == *(_DWORD *)v107 )
          {
            v36 -= 4;
            v107 += 4;
            v106 = (char *)v106 + 4;
            if ( v36 < 4 )
              goto LABEL_234;
          }
        }
      }
LABEL_252:
      v192 = 0;
      v112 = sub_42BB00(v36, v166);
      v113 = v175;
      v114 = v112;
      v179 = (char *)v112;
      v172 = sub_430970();
      if ( v172 )
      {
        if ( !sub_430B40(v115, v113) )
        {
          v171 += (v114 != 0) + 1;
          continue;
        }
        v116 = operator new(0x18u);
        v192 = v116;
        sub_430B70(v117, v113);
        sub_430B40(v118, v113);
        sub_4087F0(1);
        v119 = *((_DWORD *)v116 + 1);
        v120 = *((_DWORD *)v116 + 2);
        v198 = *(_DWORD *)v116;
        v121 = *((_DWORD *)v116 + 3);
        v199 = v119;
        v122 = *((_DWORD *)v116 + 4);
        v200 = v120;
        v123 = *((_DWORD *)v116 + 5);
        v201 = v121;
        v202 = v122;
        v203 = v123;
      }
      else
      {
        v198 = v229;
        v122 = v232;
        v199 = v230;
        v200 = v231;
        v201 = v232;
        v202 = v233;
        v203 = v234;
      }
      sub_409AE0(v122, 0);
      sub_430BA0(&v198, v113, *((_DWORD *)v169 + 12), a12);
      if ( v209 || v177 )
      {
        v223 = 0;
        if ( a10 )
        {
          v225 = v200 - 1;
        }
        else if ( v179 )
        {
          v225 = v183;
        }
        else
        {
          v225 = v183 / 2;
        }
        v224 = v268 - 1;
        v226 = v268 - 1;
        sub_409BF0(a12 | 0xFF000000);
      }
      if ( a10 )
      {
        v125 = v185;
        v257 += v185;
        sub_4091F0(v124, &v198);
        v127 = v172;
        if ( v172 )
          v128 = (void *)sub_430B40(v126, v113);
        else
          v128 = (void *)(v200 - v125);
        v167 = v128;
        if ( v127 )
          v174 = 0;
        else
          v174 = sub_408F00(v183);
LABEL_279:
        v130 = operator new(0x48u);
        v131 = dword_4F5604;
        v130[1] = v191;
        *v130 = 0;
        v130[2] = 0;
        v130[3] = v131;
        v130[14] = 0;
        v130[15] = 0;
        v130[16] = 0;
        v130[17] = 0;
        sub_4087F0(1);
        sub_409AE0(v132, 0);
        if ( *(_DWORD *)v193 )
        {
          if ( *(_DWORD *)v193 != 1 )
          {
            if ( *(_DWORD *)v193 == 2 )
            {
              sub_4087F0(1);
              sub_409AE0(v133, 0);
              sub_430CC0(&v211, *((_DWORD *)v169 + 12), v188, v190, *(_DWORD *)(v193 + 12));
              v134 = v211;
              v236 = v212;
              v237 = v213;
              v235 = v211;
              v238 = v214;
              v239 = v215;
              v240 = v216;
              if ( a10 )
                sub_4091F0(v214, &v235);
              sub_4099F0(0, 1, 256 - *(_DWORD *)(v193 + 16));
              sub_4099F0(v188, 0, 0);
              sub_49A84A(v134);
            }
            goto LABEL_287;
          }
          sub_4087F0(1);
          sub_409AE0(v135, 0);
          v136 = v193;
          sub_4169E0(*(_DWORD *)(v193 + 12));
          sub_4099F0(v188, 1, 256 - *(_DWORD *)(v136 + 16));
          sub_49A84A(v211);
        }
        sub_4099F0(0, 0, 0);
LABEL_287:
        v137 = v192;
        if ( v192 )
        {
          sub_49A84A(*(_DWORD *)v192);
          operator delete(v137);
        }
        v138 = (char *)v167 + v174;
        v139 = (_BYTE *)(v174 >> 1);
        v172 = 0;
        v219 = (char *)v167 + v174;
        v192 = (void *)(v174 >> 1);
        v167 = (void *)(v138 - v139 + sub_434970(a10));
        v174 = 0;
        v140 = (void *)((v179 != 0) + 1);
        v178 = v140;
        v141 = (char *)v140 + (_DWORD)v173 + v171;
        v220 = v141;
        v179 = v141;
        v143 = sub_435530(v142, v166);
        v144 = v143;
        if ( v143 < 1 )
        {
          v186 = 0;
        }
        else if ( v182 > 0 )
        {
          --v182;
        }
        else if ( !v186 && v143 >= 2 )
        {
          sub_432990(&v259, v205, v169, a10);
          if ( (signed int)v167 < (signed int)v259 )
            v167 = v259;
          v182 = v144 - 1;
          v174 = v144 - 1;
          v179 = &v173[v144] + v171;
        }
        if ( a5 )
        {
          if ( v197 > 0 )
          {
            --v197;
          }
          else if ( sub_432350(&v276) )
          {
            sub_432990(&v227, &v276, v169, a10);
            if ( (signed int)v167 < (signed int)v227 )
              v167 = v227;
            v145 = unknown_libname_10(strlen(&v276) + 1);
            v130[15] = v228;
            v130[14] = v145;
            v146 = &v276;
            v147 = (_BYTE *)v145;
            do
            {
              v148 = *v146;
              *v147++ = *v146++;
            }
            while ( v148 );
            v149 = sub_4325E0(0);
            v150 = v149 - 1;
            v197 = v149 - 1;
            v182 = v149 - 1;
            v179 = &v173[v171] + strlen(&v276);
            v174 = v150;
          }
        }
        if ( a11 )
        {
          if ( v196 > 0 )
          {
            --v196;
          }
          else
          {
            v152 = sub_435370(v179);
            if ( v152 <= 0 )
            {
              if ( sub_4354D0(v151, v166) && *v220 )
              {
                v155 = sub_42BAE0();
                v276 = v157;
                if ( v155 )
                {
                  v277 = *(_BYTE *)(v156 + 1);
                  v278 = 0;
                }
                else
                {
                  v277 = 0;
                }
                sub_432990(&v258, &v276, v169, a10);
                v167 = (char *)v167 + v258;
              }
            }
            else
            {
              sub_432990(&v260, &v276, v169, a10);
              v167 = (char *)v167 + v260;
              v196 = v152 + v174;
              sub_435560(&v170, v152 - 1);
              if ( dword_4F5614 )
              {
                v172 = sub_435470(v153, &v170);
                if ( v172 )
                {
                  sub_42BB00(v154, &v170);
                  v139 = v192;
                }
              }
              else
              {
                v172 = 0;
              }
            }
          }
        }
        v158 = v180;
        if ( (signed int)v167 + *(_DWORD *)v180 > *(_DWORD *)(a7 + 8) - (v172 == 0 ? v210 : 0) + 1 )
        {
          if ( v175 == v204 )
          {
            v204 = 0;
          }
          else
          {
            if ( v177 )
              v189 = v166;
            v159 = (int)&v184[*(_DWORD *)a7];
            v160 = v195;
            *(_DWORD *)(v180 + 4) += a8;
            *(_DWORD *)v158 = v159;
            ++*v160;
            v186 = 1;
          }
        }
        v161 = (int)&v139[*(_DWORD *)v158];
        v130[4] = v161;
        v162 = v161;
        v163 = v208 + *(_DWORD *)(v158 + 4);
        v130[5] = v163;
        v130[6] = v162;
        v130[7] = v163;
        v164 = sub_434970(a10);
        v165 = v194;
        *(_DWORD *)v158 += &v219[v164];
        v36 = (unsigned int)v178;
        v191 += dword_4F5600;
        v171 += (unsigned int)v178;
        *(_DWORD *)(v165 + 68) = v130;
        v194 = (int)v130;
        continue;
      }
      if ( v172 )
      {
        v129 = (void *)sub_430B40(v124, v113);
      }
      else
      {
        if ( v179 )
        {
          v167 = (void *)v183;
LABEL_278:
          v174 = 0;
          goto LABEL_279;
        }
        v129 = (void *)(v183 / 2);
      }
      v167 = v129;
      goto LABEL_278;
    }
    v167 = (void *)(v44 + 1);
    memcpy_0(v273, (const void *)v36, v42 - 1);
    *((_BYTE *)&v272 + v42 + 3) = 0;
    sub_42BB70(v46, v273);
    v47 = "/";
    v242 = "/";
    v243 = "b";
    v244 = "/b";
    v245 = "i";
    v246 = "/i";
    v247 = "ruby";
    v248 = "r";
    v249 = "/r";
    v250 = "cr";
    v251 = "c";
    v252 = "/c";
    v253 = "l";
    v254 = "/l";
    v255 = "t";
    v256 = 0;
    while ( 1 )
    {
      v48 = (unsigned int)v47;
      v49 = v273;
      while ( 1 )
      {
        v50 = (unsigned __int8)*v49 < *(_BYTE *)v48;
        if ( *v49 != *(_BYTE *)v48 )
          break;
        if ( !*v49 )
          goto LABEL_61;
        v51 = v49[1];
        v50 = (unsigned __int8)v51 < *(_BYTE *)(v48 + 1);
        if ( v51 != *(_BYTE *)(v48 + 1) )
          break;
        v49 += 2;
        v48 += 2;
        if ( !v51 )
        {
LABEL_61:
          v52 = 0;
          goto LABEL_63;
        }
      }
      v52 = -v50 - (v50 - 1);
LABEL_63:
      if ( !v52 )
        break;
      if ( !v45 )
        goto LABEL_79;
      v48 = strlen(v47);
      v53 = v47;
      v54 = v273;
      if ( v48 < 4 )
      {
LABEL_68:
        if ( !v48 )
          goto LABEL_77;
      }
      else
      {
        while ( *(_DWORD *)v54 == *(_DWORD *)v53 )
        {
          v48 -= 4;
          v53 += 4;
          v54 += 4;
          if ( v48 < 4 )
            goto LABEL_68;
        }
      }
      v55 = (unsigned __int8)*v54 - *v53;
      if ( (unsigned __int8)*v54 != *v53 )
        goto LABEL_76;
      if ( v48 > 1 )
      {
        v55 = (unsigned __int8)v54[1] - v53[1];
        if ( (unsigned __int8)v54[1] != v53[1] )
          goto LABEL_76;
        if ( v48 > 2 )
        {
          v55 = (unsigned __int8)v54[2] - v53[2];
          if ( (unsigned __int8)v54[2] != v53[2] )
            goto LABEL_76;
          if ( v48 > 3 )
          {
            v48 = v53[3];
            v55 = (unsigned __int8)v54[3] - v48;
LABEL_76:
            v56 = (v55 >> 31) | 1;
            goto LABEL_78;
          }
        }
      }
LABEL_77:
      v56 = 0;
LABEL_78:
      if ( v56 == 0 )
        break;
LABEL_79:
      v47 = (&v243)[4 * v45++];
      if ( !v47 )
      {
        v36 = v171;
        v171 += v174 + 1;
        goto LABEL_328;
      }
    }
    v57 = (&v242)[4 * v45];
    v58 = (int)(v57 + 1);
    do
      LOBYTE(v48) = *v57++;
    while ( (_BYTE)v48 );
    v59 = (char *)(&v57[(_DWORD)v273] - v58);
    switch ( v45 )
    {
      case 0:
        v36 = v171;
        v206 = 1;
        v171 += v174 + 1;
        continue;
      case 1:
        if ( v264 )
          goto LABEL_223;
        v178 = operator new(0xACu);
        v279 = 0;
        if ( v178 )
          v60 = (void (__stdcall ***)(_DWORD))sub_42A770();
        else
          v60 = 0;
        v279 = -1;
        if ( sub_42AEC0(&pszFaceName, v262, v263, 1, bItalic, (int)&v241, 64, 1) )
          goto LABEL_93;
        if ( v266 )
          (**v266)(1);
        v169 = &pszFaceName;
        v264 = 1;
        v266 = v60;
        sub_42BAB0(v181);
        v36 = v171;
        v171 += v174 + 1;
        continue;
      case 2:
        if ( !v264 )
          goto LABEL_223;
        if ( !strcmp(&pszFaceName, &v267) && v262 == v268 && v263 == v269 && bItalic == v271 )
        {
          if ( v266 )
            (**v266)(1);
          v36 = v171;
          v169 = &v267;
          v264 = 0;
          v266 = 0;
          v171 += v174 + 1;
        }
        else
        {
          v178 = operator new(0xACu);
          v279 = 1;
          if ( v178 )
            v61 = (void (__stdcall ***)(_DWORD))sub_42A770();
          else
            v61 = 0;
          v279 = -1;
          if ( sub_42AEC0(&pszFaceName, v262, v263, 0, bItalic, (int)&v241, 64, 1) )
            goto LABEL_110;
          if ( v266 )
            (**v266)(1);
          v264 = 0;
          v266 = v61;
          sub_42BAB0(v181);
          v36 = v171;
          v171 += v174 + 1;
        }
        continue;
      case 3:
        if ( bItalic )
          goto LABEL_223;
        v178 = operator new(0xACu);
        v279 = 2;
        if ( v178 )
          v61 = (void (__stdcall ***)(_DWORD))sub_42A770();
        else
          v61 = 0;
        v279 = -1;
        if ( sub_42AEC0(&pszFaceName, v262, v263, v264, 1u, (int)&v241, 64, 1) )
          goto LABEL_110;
        if ( v266 )
          (**v266)(1);
        v169 = &pszFaceName;
        bItalic = 1;
        v266 = v61;
        sub_42BAB0(v181);
        v36 = v171;
        v171 += v174 + 1;
        continue;
      case 4:
        if ( !bItalic )
          goto LABEL_223;
        if ( !strcmp(&pszFaceName, &v267) && v262 == v268 && v263 == v269 && v264 == v270 )
        {
          if ( v266 )
            (**v266)(1);
          v169 = &v267;
          v36 = v171;
          bItalic = 0;
          v266 = 0;
          v171 += v174 + 1;
        }
        else
        {
          v178 = operator new(0xACu);
          v279 = 3;
          if ( v178 )
            v61 = (void (__stdcall ***)(_DWORD))sub_42A770();
          else
            v61 = 0;
          v279 = -1;
          if ( sub_42AEC0(&pszFaceName, v262, v263, v264, 0, (int)&v241, 64, 1) )
          {
LABEL_110:
            if ( !v61 )
              goto LABEL_223;
            ((void (__thiscall *)(void (__stdcall ***)(_DWORD), signed int))**v61)(v61, 1);
            v36 = v171;
            v171 += v174 + 1;
          }
          else
          {
            if ( v266 )
              (**v266)(1);
            bItalic = 0;
            v266 = v61;
            sub_42BAB0(v181);
            v36 = v171;
            v171 += v174 + 1;
          }
        }
        continue;
      case 5:
        v274 = 0;
        v37 = *v59 == 32;
        v62 = &v275;
        v63 = &v274;
        v166 = &v275;
        v275 = 0;
        if ( v37 )
        {
          do
            ++v59;
          while ( *v59 == 32 );
        }
        while ( 1 )
        {
          v64 = sub_42BB00(v62, v59);
          if ( !v64 )
          {
            LOBYTE(v62) = *v59;
            if ( !*v59 )
              goto LABEL_223;
            if ( (_BYTE)v62 == 44 )
              break;
          }
          for ( i = (v64 != 0) + 1; i; --i )
          {
            LOBYTE(v62) = *v59;
            *v63++ = *v59++;
          }
        }
        v66 = v59 + 1;
        while ( 1 )
        {
          v67 = sub_42BB00(v62, v66);
          if ( !v67 && !*v66 )
            break;
          v68 = (v67 != 0) + 1;
          if ( (v67 != 0) != -1 )
          {
            memcpy_0(v166, v66, (v67 != 0) + 1);
            v66 += v68;
            v166 = (char *)v166 + v68;
          }
        }
        *(_BYTE *)v166 = 0;
        v69 = v207;
        *v63 = 0;
        sub_431FB0(v69, &v274, &v275, 1);
        v36 = v171;
        v171 += v174 + 1;
        continue;
      case 6:
        for ( ; *v59 == 32; ++v59 )
          ;
        v70 = &v275;
        while ( 1 )
        {
          v71 = sub_42BB00(v48, v59);
          if ( !v71 && !*v59 )
            break;
          v72 = (v71 != 0) + 1;
          if ( (v71 != 0) != -1 )
          {
            memcpy_0(v70, v59, (v71 != 0) + 1);
            v59 += v72;
            v70 += v72;
          }
        }
        *v70 = 0;
        if ( !v275 )
          goto LABEL_223;
        v73 = v167;
        v74 = *(_BYTE *)v167;
        v166 = &v274;
        if ( !v74 )
          goto LABEL_223;
        v75 = (char *)v167;
        break;
      case 8:
        v36 = v171;
        *(_DWORD *)v180 = *(_DWORD *)a7;
        v171 = v36 + v174 + 1;
        continue;
      case 9:
        for ( ; *v59 == 32; ++v59 )
          ;
        v79 = 0;
        v80 = 0;
        do
        {
          v81 = strchr("0123456789abcdef", v59[v80]);
          if ( !v81 )
            break;
          ++v80;
          v79 = (v81 - "0123456789abcdef") | 16 * v79;
        }
        while ( v80 < 6 );
        if ( v80 != 6 )
          goto LABEL_223;
        v82 = v176 + 1;
        v83 = (void *)unknown_libname_10(4 * (v176 + 1) | -((unsigned __int64)(unsigned int)(v176 + 1) >> 30 != 0));
        v84 = v176;
        if ( v176 )
        {
          memcpy_0(v83, v168, 4 * v176);
          v84 = v176;
        }
        *((_DWORD *)v83 + v84) = a12;
        v176 = v82;
        sub_49A84A(v168);
        v36 = v171;
        v168 = v83;
        a12 = v79;
        v171 += v174 + 1;
        continue;
      case 10:
        if ( !v176 )
          goto LABEL_223;
        v36 = v171;
        a12 = *((_DWORD *)v168 + v176-- - 1);
        v171 += v174 + 1;
        continue;
      case 11:
        if ( v177 )
          goto LABEL_223;
        v85 = *(_DWORD *)(v180 + 4);
        v86 = v176;
        v217 = *(_DWORD *)v180;
        v218 = v85;
        v177 = v167;
        v87 = v176 + 1;
        v88 = (void *)unknown_libname_10(4 * (v176 + 1) | -((unsigned __int64)(unsigned int)(v176 + 1) >> 30 != 0));
        if ( v86 )
          memcpy_0(v88, v168, 4 * v86);
        v89 = v168;
        *((_DWORD *)v88 + v86) = a12;
        v176 = v87;
        sub_49A84A(v89);
        v168 = v88;
        if ( v222 != -1 )
          a12 = v222;
        if ( v264 || bItalic )
          goto LABEL_223;
        v90 = ::pszFaceName;
        if ( !strlen(::pszFaceName) )
          v90 = &pszFaceName;
        if ( dword_54A5E4 <= 0 )
          v172 = v262;
        else
          v172 = dword_54A5E4;
        v91 = dword_54A5E8;
        if ( dword_54A5E8 <= 0 )
          v91 = v263;
        v178 = operator new(0xACu);
        v279 = 4;
        if ( v178 )
          v60 = (void (__stdcall ***)(_DWORD))sub_42A770();
        else
          v60 = 0;
        v279 = -1;
        v92 = sub_407360();
        if ( sub_42AEC0(v90, v172, v91, dword_54A5EC, ::bItalic, v92, 64, 1) )
        {
LABEL_93:
          if ( !v60 )
            goto LABEL_223;
          ((void (__thiscall *)(void (__stdcall ***)(_DWORD), signed int))**v60)(v60, 1);
          v36 = v171;
          v171 += v174 + 1;
        }
        else
        {
          if ( v266 )
            (**v266)(1);
          v169 = &pszFaceName;
          v266 = v60;
          sub_42BAB0(v181);
          v36 = v171;
          v171 += v174 + 1;
        }
        continue;
      case 12:
        if ( !v177 )
          goto LABEL_223;
        if ( v189 )
        {
          v93 = v189 - (_BYTE *)v177;
          v189 = 0;
        }
        else
        {
          v93 = v171 + v173 - (_BYTE *)v177;
        }
        if ( v93 )
        {
          v94 = v93;
          if ( v93 >= 0x60 )
            v94 = 95;
          memcpy_0(v273, v177, v94);
          v95 = v218;
          v96 = v217;
          v273[v93] = 0;
          v177 = 0;
          sub_4357A0(v273, v96, v95);
        }
        if ( v176 )
          a12 = *((_DWORD *)v168 + --v176);
        if ( v264 || bItalic )
          goto LABEL_223;
        if ( v266 )
          (**v266)(1);
        v169 = &v267;
        v36 = v171;
        v266 = 0;
        v171 += v174 + 1;
        continue;
      case 13:
        for ( j = &v274; *v59 == 32; ++v59 )
          ;
        if ( !sub_42BB00(v48, v59) )
        {
          v99 = v59 - &v274;
          do
          {
            v100 = j[v99];
            if ( v100 < 48 )
              break;
            if ( v100 > 57 )
              break;
            *j++ = v100;
          }
          while ( !sub_42BB00(v98, &j[v99]) );
        }
        *j = 0;
        v191 = dword_4F5600 * atoi(&v274);
        goto LABEL_223;
      default:
LABEL_223:
        v36 = v171;
        v171 += v174 + 1;
        continue;
    }
    while ( 1 )
    {
      v76 = sub_42BB00(v73, v75);
      if ( !v76 && v74 == 60 )
        break;
      v77 = (v76 != 0) + 1;
      if ( (v76 != 0) != -1 )
      {
        v78 = (char *)v166;
        memcpy_0(v166, v75, (v76 != 0) + 1);
        v75 += v77;
        v166 = &v78[v77];
      }
      v74 = *v75;
      if ( !*v75 )
      {
        v36 = v171;
        v171 += v174 + 1;
        goto LABEL_328;
      }
    }
    *(_BYTE *)v166 = 0;
    if ( !v274 )
      goto LABEL_223;
    sub_431FB0(v207, &v274, &v275, 1);
    v36 = v171;
    v171 += v174 + 1;
LABEL_328:
    ;
  }
  while ( v173[v171] );
LABEL_329:
  sub_49A84A(v168);
  if ( v266 )
    (**v266)(1);
  sub_49A84A(v205);
  sub_49A84A(v229);
  return v221;
}
}