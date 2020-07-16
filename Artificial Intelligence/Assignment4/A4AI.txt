#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

void readData(vector<vector <char>>& Dat){
	ifstream fin("sample.dat");
	vector <char> Line;
	char ch;
	while(!fin.eof()){
		for (int i = 0; i < 22; i++){
			fin >> ch;
			Line.push_back(ch);
			fin >> ch;	//to ignore ,
		}
		fin >> ch;
		Line.push_back(ch);
		Dat.push_back(Line);
		Line.clear();
	}
	Dat.pop_back();
	fin.close();
}

//void Count(vector<vector <char>>& Dat, double &CE, double &CP){
//	for (int i = 0; i < Dat.size(); i++){
//			if (Dat[i][0] == 'e'){
//				CE++;
//			}
//			else if (Dat[i][0] == 'p'){
//				CP++;
//			}
//	}
//}

void GenericCount(vector<vector <char>>& DS, vector <char>& Choice, vector <double>& ChoiceValues, int index){
	for (int i = 0; i < Choice.size(); i++){
		for (int j = 0; j < DS.size(); j++){
			if (DS[j][index] == Choice[i]){
				ChoiceValues[i]++;
			}
		}
	}
}

void Calculation(vector<vector <char>>& DS, vector <char>& Choice, vector <double>& ChoiceValues, vector <double>& Sol, vector <int>& Total, int index, double CE, double CP){
	for (int i = 0; i < Choice.size(); i++){
		double TotalE = 0, TotalP = 0;
		for (int j = 0; j < DS.size(); j++){
			if (DS[j][index] == Choice[i]){
				if (DS[j][0] == 'e')
					TotalE++;
				else if (DS[j][0] == 'p')
					TotalP++;
			}
		}
		double val;
		if (TotalE == 0 || TotalP == 0){
			val = 0;
		}
		else{
			val = ((TotalE / CE)*(log2(TotalE / CE))) + ((TotalP / CP)*(log2(TotalP / CP)));
		}
		double Res = abs(val);
		Sol.push_back(Res);
		Total.push_back(TotalE + TotalP);
	}
}

double CalEntropy(vector <double>& Sol, vector <int>& Total, double T){
	double Res = 0;
	for (int i = 0; i < Sol.size(); i++)
		Res += (Total[i] / T)*(Sol[i]);
	return Res;
}

double CalGain(double IG, double Ent){
	return IG - Ent;
}

int main(){
	cout << setprecision(5);
	vector <vector <char>> Sample;
	readData(Sample);
	//Print
	/*for (int i = 0; i < Sample.size(); i++){
		for (int j = 0; j < Sample[i].size(); j++){
			cout << Sample[i][j] << '\t';
		}
		cout << '\n';
	}*/

	double Total = Sample.size();
	map <string, double> Entropy;
	map <string, double> Gain;

	//double CountE = 0, CountP = 0;
	//Count(Sample, CountE, CountP);
	//cout << CountE << '\t' << CountP << '\n';
	////double InfoGainClass = abs(((CountE / Total)*(log2(CountE / Total))) + ((CountP / Total)*(log2(CountP / Total))));
	////cout << "Information Gain of Class : " << InfoGainClass << '\n';

	double CountE, CountP;
	vector <char> Classes;
	Classes.push_back('e');
	Classes.push_back('p');
	vector <double> ClassesValues(Classes.size(), 0);
	GenericCount(Sample, Classes, ClassesValues, 0);
	CountE = ClassesValues[0];
	CountP = ClassesValues[1];
	double InfoGainClass = abs(((CountE / Total)*(log2(CountE / Total))) + ((CountP / Total)*(log2(CountP / Total))));
	cout << "Information Gain of Class : " << InfoGainClass << '\n';


	vector <char> CapShape;
	CapShape.push_back('b');
	CapShape.push_back('c');
	CapShape.push_back('x');
	CapShape.push_back('f');
	CapShape.push_back('k');
	CapShape.push_back('s');
	vector <double> CapShapeValues(CapShape.size(), 0);
	GenericCount(Sample, CapShape, CapShapeValues, 1);
	vector <double> SolCSh;
	vector <int> TotalCSh;
	Calculation(Sample, CapShape, CapShapeValues, SolCSh, TotalCSh, 1, CountE, CountP);
	Entropy.insert(pair<string, double>("CapShape", CalEntropy(SolCSh, TotalCSh, Total)));
	Gain.insert(pair<string, double>("CapShape", CalGain(InfoGainClass, Entropy["CapShape"])));



	vector <char> CapSurface;
	CapSurface.push_back('f');
	CapSurface.push_back('g');
	CapSurface.push_back('y');
	CapSurface.push_back('s');
	vector <double> CapSufaceValues(CapSurface.size(), 0);
	GenericCount(Sample, CapSurface, CapSufaceValues, 2);
	vector <double> SolCSu;
	vector <int> TotalCSu;
	Calculation(Sample, CapSurface, CapSufaceValues, SolCSu, TotalCSu, 2, CountE, CountP);
	Entropy.insert(pair<string, double>("CapSurface", CalEntropy(SolCSu, TotalCSu, Total)));
	Gain.insert(pair<string, double>("CapSurface", CalGain(InfoGainClass, Entropy["CapSurface"])));




	vector <char> CapColor;
	CapColor.push_back('n');
	CapColor.push_back('b');
	CapColor.push_back('c');
	CapColor.push_back('g');
	CapColor.push_back('r');
	CapColor.push_back('p');
	CapColor.push_back('u');
	CapColor.push_back('e');
	CapColor.push_back('w');
	CapColor.push_back('y');
	CapColor.push_back('t');
	CapColor.push_back('f');
	vector <double> CapColorValues(CapColor.size(), 0);
	GenericCount(Sample, CapColor, CapColorValues, 3);
	vector <double> SolCCo;
	vector <int> TotalCCo;
	Calculation(Sample, CapColor, CapColorValues, SolCCo, TotalCCo, 3, CountE, CountP);
	Entropy.insert(pair<string, double>("CapColor", CalEntropy(SolCCo, TotalCCo, Total)));
	Gain.insert(pair<string, double>("CapColor", CalGain(InfoGainClass, Entropy["CapColor"])));





	vector <char> Bruises;
	Bruises.push_back('t');
	Bruises.push_back('f');
	vector <double> BruisesValues(Bruises.size(), 0);
	GenericCount(Sample, Bruises, BruisesValues, 4);
	vector <double> SolBru;
	vector <int> TotalBru;
	Calculation(Sample, Bruises, BruisesValues, SolBru, TotalBru, 4, CountE, CountP);
	Entropy.insert(pair<string, double>("Bruises", CalEntropy(SolBru, TotalBru, Total)));
	Gain.insert(pair<string, double>("Bruises", CalGain(InfoGainClass, Entropy["Bruises"])));






	vector <char> Odor;
	Odor.push_back('a');
	Odor.push_back('l');
	Odor.push_back('c');
	Odor.push_back('y');
	Odor.push_back('f');
	Odor.push_back('m');
	Odor.push_back('n');
	Odor.push_back('p');
	Odor.push_back('s');
	vector <double> OdorValues(Odor.size(), 0);
	GenericCount(Sample, Odor, OdorValues, 5);
	vector <double> SolOd;
	vector <int> TotalOd;
	Calculation(Sample, Odor, OdorValues, SolOd, TotalOd, 5, CountE, CountP);
	Entropy.insert(pair<string, double>("Odor", CalEntropy(SolOd, TotalOd, Total)));
	Gain.insert(pair<string, double>("Odor", CalGain(InfoGainClass, Entropy["Odor"])));
	




	vector <char> GillAchivement;
	GillAchivement.push_back('a');
	GillAchivement.push_back('d');
	GillAchivement.push_back('f');
	GillAchivement.push_back('n');
	vector <double> GillAchivementValues(GillAchivement.size(), 0);
	GenericCount(Sample, GillAchivement, GillAchivementValues, 6);
	vector <double> SolGAc;
	vector <int> TotalGAc;
	Calculation(Sample, GillAchivement, GillAchivementValues, SolGAc, TotalGAc, 6, CountE, CountP);
	Entropy.insert(pair<string, double>("GillAch", CalEntropy(SolGAc, TotalGAc, Total)));
	Gain.insert(pair<string, double>("GillAch", CalGain(InfoGainClass, Entropy["GillAch"])));





	vector <char> GillSpacing;
	GillSpacing.push_back('c');
	GillSpacing.push_back('w');
	GillSpacing.push_back('d');
	vector <double> GillSpacingValues(GillSpacing.size(), 0);
	GenericCount(Sample, GillSpacing, GillSpacingValues, 7);
	vector <double> SolGSp;
	vector <int> TotalGSp;
	Calculation(Sample, GillSpacing, GillSpacingValues, SolGSp, TotalGSp, 7, CountE, CountP);
	Entropy.insert(pair<string, double>("GillSp", CalEntropy(SolGSp, TotalGSp, Total)));
	Gain.insert(pair<string, double>("GillSp", CalGain(InfoGainClass, Entropy["GillSp"])));




	vector <char> GillSize;
	GillSize.push_back('b');
	GillSize.push_back('n');
	vector <double> GillSizeValues(GillSize.size(), 0);
	GenericCount(Sample, GillSize, GillSizeValues, 8);
	vector <double> SolGSi;
	vector <int> TotalGSi;
	Calculation(Sample, GillSize, GillSizeValues, SolGSi, TotalGSi, 8, CountE, CountP);
	Entropy.insert(pair<string, double>("GillSi", CalEntropy(SolGSi, TotalGSi, Total)));
	Gain.insert(pair<string, double>("GillSi", CalGain(InfoGainClass, Entropy["GillSi"])));





	vector <char> GillColor;
	GillColor.push_back('k');
	GillColor.push_back('n');
	GillColor.push_back('b');
	GillColor.push_back('h');
	GillColor.push_back('g');
	GillColor.push_back('r');
	GillColor.push_back('o');
	GillColor.push_back('p');
	GillColor.push_back('u');
	GillColor.push_back('e');
	GillColor.push_back('w');
	GillColor.push_back('y');
	vector <double> GillColorValues(GillColor.size(), 0);
	GenericCount(Sample, GillColor, GillColorValues, 9);
	vector <double> SolGCo;
	vector <int> TotalGCo;
	Calculation(Sample, GillColor, GillColorValues, SolGCo, TotalGCo, 9, CountE, CountP);
	Entropy.insert(pair<string, double>("GCO", CalEntropy(SolGCo, TotalGCo, Total)));
	Gain.insert(pair<string, double>("GCO", CalGain(InfoGainClass, Entropy["GCO"])));







	vector <char> StalkShape;
	StalkShape.push_back('e');
	StalkShape.push_back('t');
	vector <double> StalkShapeValues(StalkShape.size(), 0);
	GenericCount(Sample, StalkShape, StalkShapeValues, 10);
	vector <double> SolSSh;
	vector <int> TotalSSh;
	Calculation(Sample, StalkShape, StalkShapeValues, SolSSh, TotalSSh, 10, CountE, CountP);
	Entropy.insert(pair<string, double>("SSh", CalEntropy(SolSSh, TotalSSh, Total)));
	Gain.insert(pair<string, double>("SSh", CalGain(InfoGainClass, Entropy["SSh"])));






	vector <char> StalkRoot;
	StalkRoot.push_back('b');
	StalkRoot.push_back('c');
	StalkRoot.push_back('u');
	StalkRoot.push_back('e');
	StalkRoot.push_back('z');
	StalkRoot.push_back('r');
	StalkRoot.push_back('?');
	vector <double> StalkRootValues(StalkRoot.size(), 0);
	GenericCount(Sample, StalkRoot, StalkRootValues, 11);
	vector <double> SolSRo;
	vector <int> TotalSRo;
	Calculation(Sample, StalkRoot, StalkRootValues, SolSRo, TotalSRo, 11, CountE, CountP);
	Entropy.insert(pair<string, double>("SRo", CalEntropy(SolSRo, TotalSRo, Total)));
	Gain.insert(pair<string, double>("SRo", CalGain(InfoGainClass, Entropy["SRo"])));






	vector <char> SSAR;
	SSAR.push_back('f');
	SSAR.push_back('y');
	SSAR.push_back('k');
	SSAR.push_back('s');
	vector <double> SSARValues(SSAR.size(), 0);
	GenericCount(Sample, SSAR, SSARValues, 12);
	vector <double> SolSAR;
	vector <int> TotalSAR;
	Calculation(Sample, SSAR, SSARValues, SolSAR, TotalSAR, 12, CountE, CountP);
	Entropy.insert(pair<string, double>("SAR", CalEntropy(SolSAR, TotalSAR, Total)));
	Gain.insert(pair<string, double>("SAR", CalGain(InfoGainClass, Entropy["SAR"])));







	vector <char> SSBR;
	SSBR.push_back('f');
	SSBR.push_back('y');
	SSBR.push_back('k');
	SSBR.push_back('s');
	vector <double> SSBRValues(SSBR.size(), 0);
	GenericCount(Sample, SSBR, SSBRValues, 13);
	vector <double> SolSBR;
	vector <int> TotalSBR;
	Calculation(Sample, SSBR, SSBRValues, SolSBR, TotalSBR, 13, CountE, CountP);
	Entropy.insert(pair<string, double>("SBR", CalEntropy(SolSBR, TotalSBR, Total)));
	Gain.insert(pair<string, double>("SBR", CalGain(InfoGainClass, Entropy["SBR"])));








	vector <char> SCAR;
	SCAR.push_back('n');
	SCAR.push_back('b');
	SCAR.push_back('c');
	SCAR.push_back('g');
	SCAR.push_back('o');
	SCAR.push_back('p');
	SCAR.push_back('e');
	SCAR.push_back('w');
	SCAR.push_back('y');
	vector <double> SCARValues(SCAR.size(), 0);
	GenericCount(Sample, SCAR, SCARValues, 14);
	vector <double> SolCAR;
	vector <int> TotalCAR;
	Calculation(Sample, SCAR, SCARValues, SolCAR, TotalCAR, 14, CountE, CountP);
	Entropy.insert(pair<string, double>("CAR", CalEntropy(SolCAR, TotalCAR, Total)));
	Gain.insert(pair<string, double>("CAR", CalGain(InfoGainClass, Entropy["CAR"])));






	
	vector <char> SCBR;
	SCBR.push_back('n');
	SCBR.push_back('b');
	SCBR.push_back('c');
	SCBR.push_back('g');
	SCBR.push_back('o');
	SCBR.push_back('p');
	SCBR.push_back('e');
	SCBR.push_back('w');
	SCBR.push_back('y');
	vector <double> SCBRValues(SCBR.size(), 0);
	GenericCount(Sample, SCBR, SCBRValues, 15);
	vector <double> SolCBR;
	vector <int> TotalCBR;
	Calculation(Sample, SCBR, SCBRValues, SolCBR, TotalCBR, 15, CountE, CountP);
	Entropy.insert(pair<string, double>("CBR", CalEntropy(SolCBR, TotalCBR, Total)));
	Gain.insert(pair<string, double>("CBR", CalGain(InfoGainClass, Entropy["CBR"])));








	vector <char> VType;
	VType.push_back('p');
	VType.push_back('u');
	vector <double> VTypeValues(VType.size(), 0);
	GenericCount(Sample, VType, VTypeValues, 16);
	vector <double> SolVTy;
	vector <int> TotalVTy;
	Calculation(Sample, VType, VTypeValues, SolVTy, TotalVTy, 16, CountE, CountP);
	Entropy.insert(pair<string, double>("VTy", CalEntropy(SolVTy, TotalVTy, Total)));
	Gain.insert(pair<string, double>("VTy", CalGain(InfoGainClass, Entropy["VTy"])));








	vector <char> VColor;
	VColor.push_back('n');
	VColor.push_back('o');
	VColor.push_back('w');
	VColor.push_back('y');
	vector <double> VColorValues(VColor.size(), 0);
	GenericCount(Sample, VColor, VColorValues, 17);
	vector <double> SolVCo;
	vector <int> TotalVCo;
	Calculation(Sample, VColor, VColorValues, SolVCo, TotalVCo, 17, CountE, CountP);
	Entropy.insert(pair<string, double>("VCo", CalEntropy(SolVCo, TotalVCo, Total)));
	Gain.insert(pair<string, double>("VCo", CalGain(InfoGainClass, Entropy["VCo"])));









	vector <char> RNo;
	RNo.push_back('n');
	RNo.push_back('o');
	RNo.push_back('t');
	vector <double> RNoValues(RNo.size(), 0);
	GenericCount(Sample, RNo, RNoValues, 18);
	vector <double> SolRNo;
	vector <int> TotalRNo;
	Calculation(Sample, RNo, RNoValues, SolRNo, TotalRNo, 18, CountE, CountP);
	Entropy.insert(pair<string, double>("RNo", CalEntropy(SolRNo, TotalRNo, Total)));
	Gain.insert(pair<string, double>("RNo", CalGain(InfoGainClass, Entropy["RNo"])));





	vector <char> RType;
	RType.push_back('c');
	RType.push_back('e');
	RType.push_back('f');
	RType.push_back('l');
	RType.push_back('n');
	RType.push_back('p');
	RType.push_back('s');
	RType.push_back('z');
	vector <double> RTypeValues(RType.size(), 0);
	GenericCount(Sample, RType, RTypeValues, 19);
	vector <double> SolRTy;
	vector <int> TotalRTy;
	Calculation(Sample, RType, RTypeValues, SolRTy, TotalRTy, 19, CountE, CountP);
	Entropy.insert(pair<string, double>("RTy", CalEntropy(SolRTy, TotalRTy, Total)));
	Gain.insert(pair<string, double>("RTy", CalGain(InfoGainClass, Entropy["RTy"])));






	vector <char> SPColor;
	SPColor.push_back('k');
	SPColor.push_back('n');
	SPColor.push_back('b');
	SPColor.push_back('h');
	SPColor.push_back('r');
	SPColor.push_back('o');
	SPColor.push_back('u');
	SPColor.push_back('w');
	SPColor.push_back('y');
	vector <double> SPColorValues(SPColor.size(), 0);
	GenericCount(Sample, SPColor, SPColorValues, 20);
	vector <double> SolSPC;
	vector <int> TotalSPC;
	Calculation(Sample, SPColor, SPColorValues, SolSPC, TotalSPC, 20, CountE, CountP);
	Entropy.insert(pair<string, double>("SPC", CalEntropy(SolSPC, TotalSPC, Total)));
	Gain.insert(pair<string, double>("SPC", CalGain(InfoGainClass, Entropy["SPC"])));


	
	
	
	
	vector <char> Population;
	Population.push_back('a');
	Population.push_back('c');
	Population.push_back('n');
	Population.push_back('s');
	Population.push_back('v');
	Population.push_back('y');
	vector <double> PopulationValues(Population.size(), 0);
	GenericCount(Sample, Population, PopulationValues, 21);
	vector <double> SolPop;
	vector <int> TotalPop;
	Calculation(Sample, Population, PopulationValues, SolPop, TotalPop, 21, CountE, CountP);
	Entropy.insert(pair<string, double>("Pop", CalEntropy(SolPop, TotalPop, Total)));
	Gain.insert(pair<string, double>("Pop", CalGain(InfoGainClass, Entropy["Pop"])));







	vector <char> Habitat;
	Habitat.push_back('g');
	Habitat.push_back('l');
	Habitat.push_back('m');
	Habitat.push_back('p');
	Habitat.push_back('u');
	Habitat.push_back('w');
	Habitat.push_back('d');
	vector <double> HabitatValues(Habitat.size(), 0);
	GenericCount(Sample, Habitat, HabitatValues, 22);
	vector <double> SolHab;
	vector <int> TotalHab;
	Calculation(Sample, Habitat, HabitatValues, SolHab, TotalHab, 22, CountE, CountP);
	Entropy.insert(pair<string, double>("Hab", CalEntropy(SolHab, TotalHab, Total)));
	Gain.insert(pair<string, double>("Hab", CalGain(InfoGainClass, Entropy["Hab"])));


	
	cout << "Type\t\t\tEntropy\t\t\tGain\n";
	cout << "CapShape\t\t" << Entropy["CapShape"] << "\t\t\t" << Gain["CapShape"] << '\n';
	cout << "CapSurface\t\t" << Entropy["CapSurface"] << "\t\t\t" << Gain["CapSurface"] << '\n';
	cout << "CapColor\t\t" << Entropy["CapColor"] << "\t\t\t" << Gain["CapColor"] << '\n';
	cout << "Bruises\t\t\t" << Entropy["Bruises"] << "\t\t\t" << Gain["Bruises"] << '\n';
	cout << "Odor\t\t\t" << Entropy["Odor"] << "\t\t\t" << Gain["Odor"] << '\n';
	cout << "GillAch\t\t\t" << Entropy["GillAch"] << "\t\t\t" << Gain["GillAch"] << '\n';
	cout << "GillSp\t\t\t" << Entropy["GillSp"] << "\t\t\t" << Gain["GillSp"] << '\n';
	cout << "GillSi\t\t\t" << Entropy["GillSi"] << "\t\t\t" << Gain["GillSi"] << '\n';
	cout << "GCO\t\t\t" << Entropy["GCO"] << "\t\t\t" << Gain["GCO"] << '\n';
	cout << "SSh\t\t\t" << Entropy["SSh"] << "\t\t\t" << Gain["SSh"] << '\n';
	cout << "SRo\t\t\t" << Entropy["SRo"] << "\t\t\t" << Gain["SRo"] << '\n';
	cout << "SAR\t\t\t" << Entropy["SAR"] << "\t\t\t" << Gain["SAR"] << '\n';
	cout << "SBR\t\t\t" << Entropy["SBR"] << "\t\t\t" << Gain["SBR"] << '\n';
	cout << "CAR\t\t\t" << Entropy["CAR"] << "\t\t\t" << Gain["CAR"] << '\n';
	cout << "CBR\t\t\t" << Entropy["CBR"] << "\t\t\t" << Gain["CBR"] << '\n';
	cout << "VTy\t\t\t" << Entropy["VTy"] << "\t\t\t" << Gain["VTy"] << '\n';
	cout << "VCo\t\t\t" << Entropy["VCo"] << "\t\t\t" << Gain["VCo"] << '\n';
	cout << "RNo\t\t\t" << Entropy["RNo"] << "\t\t\t" << Gain["RNo"] << '\n';
	cout << "RTy\t\t\t" << Entropy["RTy"] << "\t\t\t" << Gain["RTy"] << '\n';
	cout << "SPC\t\t\t" << Entropy["SPC"] << "\t\t\t" << Gain["SPC"] << '\n';
	cout << "Pop\t\t\t" << Entropy["Pop"] << "\t\t\t" << Gain["Pop"] << '\n';
	cout << "Hab\t\t\t" << Entropy["Hab"] << "\t\t\t" << Gain["Hab"] << '\n';


	system("PAUSE");
	return 0;
}