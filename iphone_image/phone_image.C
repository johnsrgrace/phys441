#include "TASImage.h"
#include "TH2.h"
#include "TStyle.h"

#include <iostream>
using namespace std;

void phone_image( const char* fname = "hurling_swing/image-800.jpeg", int x = 826, int y = 420 )
{

  gStyle->SetCanvasColor(0);
  gStyle->SetFrameFillColor(0);

  gStyle->SetPadTopMargin(.08);
  gStyle->SetPadLeftMargin(.08);
  gStyle->SetPadRightMargin(.12);
  gStyle->SetPadBottomMargin(.08);

  gStyle->SetTitleOffset(1.2, "X");
  gStyle->SetTitleOffset(1.2, "Y");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleSize(0.04,"X");
  gStyle->SetTitleSize(0.04,"Y");

  gStyle->SetLabelOffset(0.01, "X");
  gStyle->SetLabelOffset(0.01, "Y");
  gStyle->SetLabelFont(42,"X");
  gStyle->SetLabelFont(42,"Y");
  gStyle->SetLabelSize(0.04,"X");
  gStyle->SetLabelSize(0.04,"Y");

  gStyle->SetNdivisions(506,"X");
  gStyle->SetNdivisions(506,"Y");

  gStyle->SetOptStat(0);
  gStyle->SetStripDecimals(kFALSE);

  TASImage image( fname );
  UInt_t yPixels = image.GetHeight();
  UInt_t xPixels = image.GetWidth();
  UInt_t *argb   = image.GetArgbArray();

  TH2D *h = new TH2D("h", "", xPixels, 0, xPixels, yPixels, 0, yPixels );
  
  for ( UInt_t row = 0; row < xPixels; ++row ) {
    for ( UInt_t col = 0; col < yPixels; ++col ) {
      UInt_t index = col*xPixels+row;
      float grey   = float(argb[index]&0xffffff)/16777216;
      h->SetBinContent( row+1, yPixels-col, grey );
    }
  }

  h->Draw("colz");
//   h->GetXaxis()->SetRange( x - 25, x + 25 );
//   h->GetYaxis()->SetRange( y - 25, y + 25 );


//   cin.ignore();
}

