#include <vcl_iostream.h>

#include <vnl/vnl_test.h>
#include <vnl/vnl_matrix.h>
#include <vnl/vnl_matlab_print.h>
#include <vnl/algo/vnl_qr.h>
#include <vnl/algo/vnl_determinant.h>

double qr_det(vnl_matrix<double> const &M) {
  return vnl_qr<double>(M).determinant();
}

void test_determinant() {
  double eps = 1e-8;

  {
    double M1[1*1] = {
      0.95012928514718
    };
    vnl_matrix<double> m1(M1,1,1);
    double d1 = M1[0];
    vnl_test_assert_near("M1", vnl_determinant(m1), d1, eps);
    vnl_test_assert_near("M1", qr_det(m1), d1, eps);
    double const * const M1_[]={M1};
    vnl_test_assert_near("M1", vnl_determinant(M1_, 1), d1, eps);
  }

  {
    double N1[1*1] = {
      -0.95012928514718
    };
    vnl_matrix<double> n1(N1,1,1);
    double d1 = N1[0];
    vnl_test_assert_near("N1", vnl_determinant(n1), d1, eps);
    vnl_test_assert_near("N1", qr_det(n1), d1, eps);
    double const * const N1_[]={N1};
    vnl_test_assert_near("N1", vnl_determinant(N1_, 1), d1, eps);
  }

  {
    double M2[2*2] = {
      0.60684258354179,   0.89129896614890,
      0.48598246870930,   0.76209683302739
    };
    vnl_matrix<double> m2(M2,2,2);
    double d2 = qr_det(m2);
    vnl_test_assert_near("M2", vnl_determinant(m2), d2, eps);
    vnl_test_assert_near("M2", vnl_determinant(M2,M2+2), d2, eps);
    double const * const M2_[]={M2, M2+2};
    vnl_test_assert_near("M2", vnl_determinant(M2_, 2), d2, eps);
  }

  {
    double N2[2*2] = {
      0.60684258354179,   0.89129896614890,
      0.48598246870930,  -0.76209683302739
    };
    vnl_matrix<double> n2(N2,2,2);
    double d2 = qr_det(n2);
    vnl_test_assert_near("N2", vnl_determinant(n2), d2, eps);
    vnl_test_assert_near("N2", vnl_determinant(N2,N2+2), d2, eps);
    double const * const N2_[]={N2, N2+2};
    vnl_test_assert_near("N2", vnl_determinant(N2_, 2), d2, eps);
  }

  {
    double M3[3*3] = {
      0.45646766516834,   0.44470336435319,   0.92181297074480,
      0.01850364324822,   0.61543234810009,   0.73820724581067,
      0.82140716429525,   0.79193703742704,   0.17626614449462
    };
    vnl_matrix<double> m3(M3,3,3);
    double d3 = qr_det(m3);
    vnl_test_assert_near("M3", vnl_determinant(m3), d3, eps);
    vnl_test_assert_near("M3", vnl_determinant(M3,M3+3,M3+6), d3, eps);
    double const * const M3_[]={M3, M3+3, M3+6};
    vnl_test_assert_near("M3", vnl_determinant(M3_, 3), d3, eps);
  }

  {
    double N3[3*3] = {
      0.45646766516834,   0.44470336435319,  -0.92181297074480,
      0.01850364324822,   0.61543234810009,  -0.73820724581067,
      0.82140716429525,   0.79193703742704,   0.17626614449462
    };
    vnl_matrix<double> n3(N3,3,3);
    double d3 = qr_det(n3);
    vnl_test_assert_near("N3", vnl_determinant(n3), d3, eps);
    vnl_test_assert_near("N3", vnl_determinant(N3,N3+3,N3+6), d3, eps);
    double const * const N3_[]={N3, N3+3, N3+6};
    vnl_test_assert_near("N3", vnl_determinant(N3_, 3), d3, eps);
  }

  {
    double M4[4*4] = {
      0.40570621306210,   0.89364953091353,   0.00986130066092,   0.60379247919382,
      0.93546969910761,   0.05789130478427,   0.13889088195695,   0.27218792496996,
      0.91690443991341,   0.35286813221700,   0.20276521856027,   0.19881426776106,
      0.41027020699095,   0.81316649730376,   0.19872174266149,   0.01527392702904
    };
    vnl_matrix<double> m4(M4,4,4);
    double d4 = qr_det(m4);
    vnl_test_assert_near("M4", vnl_determinant(m4), d4, eps);
    vnl_test_assert_near("M4", vnl_determinant(M4,M4+4,M4+8,M4+12), d4, eps);
    double const * const M4_[]={M4, M4+4, M4+8, M4+12};
    vnl_test_assert_near("M4", vnl_determinant(M4_, 4), d4, eps);
  }

  {
    double N4[4*4] = {
      0.40570621306210,  -0.89364953091353,   0.00986130066092,  -0.60379247919382,
      0.93546969910761,   0.05789130478427,   0.13889088195695,   0.27218792496996,
      0.91690443991341,  -0.35286813221700,   0.20276521856027,  -0.19881426776106,
      0.41027020699095,   0.81316649730376,   0.19872174266149,   0.01527392702904
    };
    vnl_matrix<double> n4(N4,4,4);
    double d4 = qr_det(n4);
    vnl_test_assert_near("N4", vnl_determinant(n4), d4, eps);
    vnl_test_assert_near("N4", vnl_determinant(N4,N4+4,N4+8,N4+12), d4, eps);
    double const * const N4_[]={N4, N4+4, N4+8, N4+12};
    vnl_test_assert_near("N4", vnl_determinant(N4_, 4), d4, eps);
  }
}

TESTMAIN(test_determinant);
