#include "common.h"

class Solution {
public:
    int jump(int A[], int n) {
        int* J = (int*)malloc((n)*sizeof(int));
        J[n-1] = 0;
        //J[n-2] = (A[n-1] >= 1) ? 1 : INT_MAX;
        for(int i = n - 2; i >= 0; --i){
            //J[i] = std::min<int>((J[i+1] + ((A[i] >= 1) ? 1 : n)),
            //((A[i] + i >= n - 1) ? 1 : n));
            int jump = n;
            J[i] = 0;
            for(int j = 1; j <= A[i] && (i + j < n ); ++j){
                jump = std::min<int>(jump, (J[i + j] + ((A[i + j] >= 1) ? 1 : n)));
            }
            J[i] = std::min<int>(jump, ((A[i] + i >= n - 1) ? 1 : n));
        }

        return J[0];
    }

    int jump_bfs(int A[], int n) {
        if(n <= 0)
            return 0;
        int l = 1;
        if (bfs(A, 0, A[0], n, &l)){
            return l;
        }
        return -1;
    }
    
    bool bfs(int A[], int p, int s, int n, int* l) {
        *l = *l + 1;
        for(int i = A[p]; i > 0; --i){
            if(p + i >= n - 1){
                return true;
            }
        }

        for(int i = A[p]; i > 0; --i){
            if(bfs(A, p + i, A[p+i], n, l)){
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv){
    int A[] = {25000,24999,24998,24997,24996,24995,24994,24993,24992,24991,24990,24989,24988,24987,24986,24985,24984,24983,24982,24981,24980,24979,24978,24977,24976,24975,24974,24973,24972,24971,24970,24969,24968,24967,24966,24965,24964,24963,24962,24961,24960,24959,24958,24957,24956,24955,24954,24953,24952,24951,24950,24949,24948,24947,24946,24945,24944,24943,24942,24941,24940,24939,24938,24937,24936,24935,24934,24933,24932,24931,24930,24929,24928,24927,24926,24925,24924,24923,24922,24921,24920,24919,24918,24917,24916,24915,24914,24913,24912,24911,24910,24909,24908,24907,24906,24905,24904,24903,24902,24901,24900,24899,24898,24897,24896,24895,24894,24893,24892,24891,24890,24889,24888,24887,24886,24885,24884,24883,24882,24881,24880,24879,24878,24877,24876,24875,24874,24873,24872,24871,24870,24869,24868,24867,24866,24865,24864,24863,24862,24861,24860,24859,24858,24857,24856,24855,24854,24853,24852,24851,24850,24849,24848,24847,24846,24845,24844,24843,24842,24841,24840,24839,24838,24837,24836,24835,24834,24833,24832,24831,24830,24829,24828,24827,24826,24825,24824,24823,24822,24821,24820,24819,24818,24817,24816,24815,24814,24813,24812,24811,24810,24809,24808,24807,24806,24805,24804,24803,24802,24801,24800,24799,24798,24797,24796,24795,24794,24793,24792,24791,24790,24789,24788,24787,24786,24785,24784,24783,24782,24781,24780,24779,24778,24777,24776,24775,24774,24773,24772,24771,24770,24769,24768,24767,24766,24765,24764,24763,24762,24761,24760,24759,24758,24757,24756,24755,24754,24753,24752,24751,24750,24749,24748,24747,24746,24745,24744,24743,24742,24741,24740,24739,24738,24737,24736,24735,24734,24733,24732,24731,24730,24729,24728,24727,24726,24725,24724,24723,24722,24721,24720,24719,24718,24717,24716,24715,24714,24713,24712,24711,24710,24709,24708,24707,24706,24705,24704,24703,24702,24701,24700,24699,24698,24697,24696,24695,24694,24693,24692,24691,24690,24689,24688,24687,24686,24685,24684,24683,24682,24681,24680,24679,24678,24677,24676,24675,24674,24673,24672,24671,24670,24669,24668,24667,24666,24665,24664,24663,24662,24661,24660,24659,24658,24657,24656,24655,24654,24653,24652,24651,24650,24649,24648,24647,24646,24645,24644,24643,24642,24641,24640,24639,24638,24637,24636,24635,24634,24633,24632,24631,24630,24629,24628,24627,24626,24625,24624,24623,24622,24621,24620,24619,24618,24617,24616,24615,24614,24613,24612,24611,24610,24609,24608,24607,24606,24605,24604,24603,24602,24601,24600,24599,24598,24597,24596,24595,24594,24593,24592,24591,24590,24589,24588,24587,24586,24585,24584,24583,24582,24581,24580,24579,24578,24577,24576,24575,24574,24573,24572,24571,24570,24569,24568,24567,24566,24565,24564,24563,24562,24561,24560,24559,24558,24557,24556,24555,24554,24553,24552,24551,24550,24549,24548,24547,24546,24545,24544,24543,24542,24541,24540,24539,24538,24537,24536,24535,24534,24533,24532,24531,24530,24529,24528,24527,24526,24525,24524,24523,24522,24521,24520,24519,24518,24517,24516,24515,24514,24513,24512,24511,24510,24509,24508,24507,24506,24505,24504,24503,24502,24501,24500,24499,24498,24497,24496,24495,24494,24493,24492,24491,24490,24489,24488,24487,24486,24485,24484,24483,24482,24481,24480,24479,24478,24477,24476,24475,24474,24473,24472,24471,24470,24469,24468,24467,24466,24465,24464,24463,24462,24461,24460,24459,24458,24457,24456,24455,24454,24453,24452,24451,24450,24449,24448,24447,24446,24445,24444,24443,24442,24441,24440,24439,24438,24437,24436,24435,24434,24433,24432,24431,24430,24429,24428,24427,24426,24425,24424,24423,24422,24421,24420,24419,24418,24417,24416,24415,24414,24413,24412,24411,24410,24409,24408,24407,24406,24405,24404,24403,24402,24401,24400,24399,24398,24397,24396,24395,24394,24393,24392,24391,24390,24389,24388,24387,24386,24385,24384,24383,24382,24381,24380,24379,24378,24377,24376,24375,24374,24373,24372,24371,24370,24369,24368,24367,24366,24365,24364,24363,24362,24361,24360,24359,24358,24357,24356,24355,24354,24353,24352,24351,24350,24349,24348,24347,24346,24345,24344,24343,24342,24341,24340,24339,24338,24337,24336,24335,24334,24333,24332,24331,24330,24329,24328,24327,24326,24325,24324,24323,24322,24321,24320,24319,24318,24317,24316,24315,24314,24313,24312,24311,24310,24309,24308,24307,24306,24305,24304,24303,24302,24301,24300,24299,24298,24297,24296,24295,24294,24293,24292,24291,24290,24289,24288,24287,24286,24285,24284,24283,24282,24281,24280,24279,24278,24277,24276,24275,24274,24273,24272,24271,24270,24269,24268,24267,24266,24265,24264,24263,24262,24261,24260,24259,24258,24257,24256,24255,24254,24253,24252,24251,24250,24249,24248,24247,24246,24245,24244,24243,24242,24241,24240,24239,24238,24237,24236,24235,24234,24233,24232,24231,24230,24229,24228,24227,24226,24225,24224,24223,24222,24221,24220,24219,24218,24217,24216,24215,24214,24213,24212,24211,24210,24209,24208,24207,24206,24205,24204,24203,24202,24201,24200,24199,24198,24197,24196,24195,24194,24193,24192,24191,24190,24189,24188,24187,24186,24185,24184,24183,24182,24181,24180,24179,24178,24177,24176,24175,24174,24173,24172,24171,24170,24169,24168,24167,24166,24165,24164,24163,24162,24161,24160,24159,24158,24157,24156,24155,24154,24153,24152,24151,24150,24149,24148,24147,24146,24145,24144,24143,24142,24141,24140,24139,24138,24137,24136,24135,24134,24133,24132,24131,24130,24129,24128,24127,24126,24125,24124,24123,24122,24121,24120,24119,24118,24117,24116,24115,24114,24113,24112,24111,24110,24109,24108,24107,24106,24105,24104,24103,24102,24101,24100,24099,24098,24097,24096,24095,24094,24093,24092,24091,24090,24089,24088,24087,24086,24085,24084,24083,24082,24081,24080,24079,24078,24077,24076,24075,24074,24073,24072,24071,24070,24069,24068,24067,24066,24065,24064,24063,24062,24061,24060,24059,24058,24057,24056,24055,24054,24053,24052,24051,24050,24049,24048,24047,24046,24045,24044,24043,24042,24041,24040,24039,24038,24037,24036,24035,24034,24033,24032,24031,24030,24029,24028,24027,24026,24025,24024,24023,24022,24021,24020,24019,24018,24017,24016,24015,24014,24013,24012,24011,24010,24009,24008,24007,24006,24005,24004,24003,24002,24001,24000,23999,23998,23997,23996,23995,23994,23993,23992,23991,23990,23989,23988,23987,23986,23985,23984,23983,23982,23981,23980,23979,23978,23977,23976,23975,23974,23973,23972,23971,23970,23969,23968,23967,23966,23965,23964,23963,23962,23961,23960,23959,23958,23957,23956,23955,23954,23953,23952,23951,23950,23949,23948,23947,23946,23945,23944,23943,23942,23941,23940,23939,23938,23937,23936,23935,23934,23933,23932,23931,23930,23929,23928,23927,23926,23925,23924,23923,23922,23921,23920,23919,23918,23917,23916,23915,23914,23913,23912,23911,23910,23909,23908,23907,23906,23905,23904,23903,23902,23901,23900,23899,23898,23897,23896,23895,23894,23893,23892,23891,23890,23889,23888,23887,23886,23885,23884,23883,23882,23881,23880,23879,23878,23877,23876,23875,23874,23873,23872,23871,23870,23869,23868,23867,23866,23865,23864,23863,23862,23861,23860,23859,23858,23857,23856,23855,23854,23853,23852,23851,23850,23849,23848,23847,23846,23845,23844,23843,23842,23841,23840,23839,23838,23837,23836,23835,23834,23833,23832,23831,23830,23829,23828,23827,23826,23825,23824,23823,23822,23821,23820,23819,23818,23817,23816,23815,23814,23813,23812,23811,23810,23809,23808,23807,23806,23805,23804,23803,23802,23801,23800,23799,23798,23797,23796,23795,23794,23793,23792,23791,23790,23789,23788,23787,23786,23785,23784,23783,23782,23781,23780,23779,23778,23777,23776,23775,23774,23773,23772,23771,23770,23769,23768,23767,23766,23765,23764,23763,23762,23761,23760,23759,23758,23757,23756,23755,23754,23753,23752,23751,23750,23749,23748,23747,23746,23745,23744,23743,23742,23741,23740,23739,23738,23737,23736,23735,23734,23733,23732,23731,23730,23729,23728,23727,23726,23725,23724,23723,23722,23721,23720,23719,23718,23717,23716,23715,23714,23713,23712,23711,23710,23709,23708,23707,23706,23705,23704,23703,23702,23701,23700,23699,23698,23697,23696,23695,23694,23693,23692,23691,23690,23689,23688,23687,23686,23685,23684,23683,23682,23681,23680,23679,23678,23677,23676,23675,23674,23673,23672,23671,23670,23669,23668,23667,23666,23665,23664,23663,23662,23661,23660,23659,23658,23657,23656,23655,23654,23653,23652,23651,23650,23649,23648,23647,23646,23645,23644,23643,23642,23641,23640,23639,23638,23637,23636,23635,23634,23633,23632,23631,23630,23629,23628,23627,23626,23625,23624,23623,23622,23621,23620,23619,23618,23617,23616,23615,23614,23613,23612,23611,23610,23609,23608,23607,23606,23605,23604,23603,23602,23601,23600,23599,23598,23597,23596,23595,23594,23593,23592,23591,23590,23589,23588,23587,23586,23585,23584,23583,23582,23581,23580,23579,23578,23577,23576,23575,23574,23573,23572,23571,23570,23569,23568,23567,23566,23565,23564,23563,23562,23561,23560,23559,23558,23557,23556,23555,23554,23553,23552,23551,23550,23549,23548,23547,23546,23545,23544,23543,23542,23541,23540,23539,23538,23537,23536,23535,23534,23533,23532,23531,23530,23529,23528,23527,23526,23525,23524,23523,23522,23521,23520,23519,23518,23517,23516,23515,23514,23513,23512,23511,23510,23509,23508,23507,23506,23505,23504,23503,23502,23501,23500,23499,23498,23497,23496,23495,23494,23493,23492,23491,23490,23489,23488,23487,23486,23485,23484,23483,23482,23481,23480,23479,23478,23477,23476,23475,23474,23473,23472,23471,23470,23469,23468,23467,23466,23465,23464,23463,23462,23461,23460,23459,23458,23457,23456,23455,23454,23453,23452,23451,23450,23449,23448,23447,23446,23445,23444,23443,23442,23441,23440,23439,23438,23437,23436,23435,23434,23433,23432,23431,23430,23429,23428,23427,23426,23425,23424,23423,23422,23421,23420,23419,23418,23417,23416,23415,23414,23413,23412,23411,23410,23409,23408,23407,23406,23405,23404,23403,23402,23401,23400,23399,23398,23397,23396,23395,23394,23393,23392,23391,23390,23389,23388,23387,23386,23385,23384,23383,23382,23381,23380,23379,23378,23377,23376,23375,23374,23373,23372,23371,23370,23369,23368,23367,23366,23365,23364,23363,23362,23361,23360,23359,23358,23357,23356,2335532,1331,1330,1329,1328,1327,1326,1325,1324,1323,1322,1321,1320,1319,1318,1317,1316,1315,1314,1313,1312,1311,1310,1309,1308,1307,1306,1305,1304,1303,1302,1301,1300,1299,1298,1297,1296,1295,1294,1293,1292,1291,1290,1289,1288,1287,1286,1285,1284,1283,1282,1281,1280,1279,1278,1277,1276,1275,1274,1273,1272,1271,1270,1269,1268,1267,1266,1265,1264,1263,1262,1261,1260,1259,1258,1257,1256,1255,1254,1253,1252,1251,1250,1249,1248,1247,1246,1245,1244,1243,1242,1241,1240,1239,1238,1237,1236,1235,1234,1233,1232,1231,1230,1229,1228,1227,1226,1225,1224,1223,1222,1221,1220,1219,1218,1217,1216,1215,1214,1213,1212,1211,1210,1209,1208,1207,1206,1205,1204,1203,1202,1201,1200,1199,1198,1197,1196,1195,1194,1193,1192,1191,1190,1189,1188,1187,1186,1185,1184,1183,1182,1181,1180,1179,1178,1177,1176,1175,1174,1173,1172,1171,1170,1169,1168,1167,1166,1165,1164,1163,1162,1161,1160,1159,1158,1157,1156,1155,1154,1153,1152,1151,1150,1149,1148,1147,1146,1145,1144,1143,1142,1141,1140,1139,1138,1137,1136,1135,1134,1133,1132,1131,1130,1129,1128,1127,1126,1125,1124,1123,1122,1121,1120,1119,1118,1117,1116,1115,1114,1113,1112,1111,1110,1109,1108,1107,1106,1105,1104,1103,1102,1101,1100,1099,1098,1097,1096,1095,1094,1093,1092,1091,1090,1089,1088,1087,1086,1085,1084,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,1044,1043,1042,1041,1040,1039,1038,1037,1036,1035,1034,1033,1032,1031,1030,1029,1028,1027,1026,1025,1024,1023,1022,1021,1020,1019,1018,1017,1016,1015,1014,1013,1012,1011,1010,1009,1008,1007,1006,1005,1004,1003,1002,1001,1000,999,998,997,996,995,994,993,992,991,990,989,988,987,986,985,984,983,982,981,980,979,978,977,976,975,974,973,972,971,970,969,968,967,966,965,964,963,962,961,960,959,958,957,956,955,954,953,952,951,950,949,948,947,946,945,944,943,942,941,940,939,938,937,936,935,934,933,932,931,930,929,928,927,926,925,924,923,922,921,920,919,918,917,916,915,914,913,912,911,910,909,908,907,906,905,904,903,902,901,900,899,898,897,896,895,894,893,892,891,890,889,888,887,886,885,884,883,882,881,880,879,878,877,876,875,874,873,872,871,870,869,868,867,866,865,864,863,862,861,860,859,858,857,856,855,854,853,852,851,850,849,848,847,846,845,844,843,842,841,840,839,838,837,836,835,834,833,832,831,830,829,828,827,826,825,824,823,822,821,820,819,818,817,816,815,814,813,812,811,810,809,808,807,806,805,804,803,802,801,800,799,798,797,796,795,794,793,792,791,790,789,788,787,786,785,784,783,782,781,780,779,778,777,776,775,774,773,772,771,770,769,768,767,766,765,764,763,762,761,760,759,758,757,756,755,754,753,752,751,750,749,748,747,746,745,744,743,742,741,740,739,738,737,736,735,734,733,732,731,730,729,728,727,726,725,724,723,722,721,720,719,718,717,716,715,714,713,712,711,710,709,708,707,706,705,704,703,702,701,700,699,698,697,696,695,694,693,692,691,690,689,688,687,686,685,684,683,682,681,680,679,678,677,676,675,674,673,672,671,670,669,668,667,666,665,664,663,662,661,660,659,658,657,656,655,654,653,652,651,650,649,648,647,646,645,644,643,642,641,640,639,638,637,636,635,634,633,632,631,630,629,628,627,626,625,624,623,622,621,620,619,618,617,616,615,614,613,612,611,610,609,608,607,606,605,604,603,602,601,600,599,598,597,596,595,594,593,592,591,590,589,588,587,586,585,584,583,582,581,580,579,578,577,576,575,574,573,572,571,570,569,568,567,566,565,564,563,562,561,560,559,558,557,556,555,554,553,552,551,550,549,548,547,546,545,544,543,542,541,540,539,538,537,536,535,534,533,532,531,530,529,528,527,526,525,524,523,522,521,520,519,518,517,516,515,514,513,512,511,510,509,508,507,506,505,504,503,502,501,500,499,498,497,496,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,479,478,477,476,475,474,473,472,471,470,469,468,467,466,465,464,463,462,461,460,459,458,457,456,455,454,453,452,451,450,449,448,447,446,445,444,443,442,441,440,439,438,437,436,435,434,433,432,431,430,429,428,427,426,425,424,423,422,421,420,419,418,417,416,415,414,413,412,411,410,409,408,407,406,405,404,403,402,401,400,399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,302,301,300,299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,277,276,275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,1,0};
    Solution s;
    cout << s.jump(A, sizeof(A)/sizeof(A[0])) << endl;
}
