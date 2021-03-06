#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include <fstream>

using namespace std;

void ntuple_to_ascii(){
  TFile *f=new TFile("dataset.root"); // file
  TTree *tr=(TTree*)f->Get("ds_k"); // tree
  tr->Scan(); // prints the content on the screen

  float pt,y,im;

  tr->SetBranchAddress("pt",&pt); // variables from a tree
  tr->SetBranchAddress("y",&y);
  tr->SetBranchAddress("im",&im);

  ofstream myfile;
  myfile.open ("ex_dataset.txt");
  myfile << "pt y im\n"; //column's names

  for (int i=0;i<tr->GetEntries();i++){
    // loop over the tree
    tr->GetEntry(i);
    cout << pt << " " << y << " "<< im << endl; //print to the screen
    myfile << pt << " " << y << " "<< im <<"\n"; //write to file
  }
  myfile.close();
}
