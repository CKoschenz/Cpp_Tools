#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vanderwaals/nmath/finite_differentiation.hpp>


class FiniteDiffTest : public testing::Test {
protected:
  FiniteDiffTest() = default;

  const std::vector<double> fct_values{init_fct()};
  const std::vector<double> true_diffs_first_order{init_first_derivative()};
  const std::vector<double> true_diffs_second_order{init_second_derivative()};

  const double accuracy{h};

private:
  static constexpr double start{0.0};
  static constexpr double end{4.0*M_PI};
  static constexpr double steps{400};
  static constexpr double h{(end-start)/steps};
  
  static class func {
    public:
      func() = default;
      double value(double x){return std::cos(x);}
      double first_derivative(double x) {return -std::sin(x);}
      double second_derivative(double x) {return -std::cos(x);}
  } function;

  static const std::vector<double> init_fct(){
    std::vector<double> temp;
    for(int i=0; i <= steps;++i)
    {
      temp.push_back(function.value(i*h));
    }
    return temp;
  }

  static const std::vector<double> init_first_derivative(){
    std::vector<double> temp;
    for(int i=0; i <= steps;++i)
    {
      temp.push_back(function.first_derivative(i*h));
    }
    return temp;
  }

  static const std::vector<double> init_second_derivative(){
    std::vector<double> temp;
    for(int i=0; i <= steps;++i)
    {
      temp.push_back(function.second_derivative(i*h));
    }
    return temp;
  }
};


/**
 * @brief Test first order of FORWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstForwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.forward_diff(1,h,this->fct_values);

  true_diffs.resize(diff.size());

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}


/**
 * @brief Test first order of ENHANCED FORWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstEnhancedForwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.forward_diff_enhanced_first_order(h,fct_values);

  true_diffs.resize(diff.size());

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h*h))));
}


/**
 * @brief Test second order of FORWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteSecondForwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_second_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.forward_diff(2,h,fct_values);

  true_diffs.resize(diff.size());

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}


/**
 * @brief Test first order of BACKWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstBackwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.backward_diff(1,h,fct_values);

  true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 1);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}


/**
 * @brief Test first order of ENHANCED BACKWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstEnhancedBackwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.backward_diff_enhanced_first_order(h,fct_values);

  true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 2);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h*h))));
}


/**
 * @brief Test second order of BACKWARD DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteSecondBackwardDiff) {

  std::vector<double> true_diffs = this->true_diffs_second_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.backward_diff(2,h,fct_values);

  true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 2);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}


/**
 * @brief Test first order of CENTRAL DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstCentralDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.central_diff(1,h,fct_values);

  true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 1);
  true_diffs.erase(true_diffs.end()-1, true_diffs.end());

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h*h))));
}


/**
 * @brief Test second order of CENTRAL DIFFERENTIATION
 * 
 */
TEST_F(FiniteDiffTest, FiniteSecondCentralDiff) {

  std::vector<double> true_diffs = this->true_diffs_second_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.central_diff(2,h,fct_values);

  true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 2);
  true_diffs.erase(true_diffs.end()-2, true_diffs.end());

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h*h))));
}


/**
 * @brief Test first order of FULL DIFFERENTIATION operation
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstFullDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.finite_diff(1,h,fct_values);

  //true_diffs.erase(true_diffs.begin(), true_diffs.begin() + 1);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}


/**
 * @brief Test first order of ENHANCED FULL DIFFERENTIATION operation
 * 
 */
TEST_F(FiniteDiffTest, FiniteFirstEnhancedFullDiff) {

  std::vector<double> true_diffs = this->true_diffs_first_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.enhanced_first_order_diff(h,fct_values);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h*h))));
}


/**
 * @brief Test second order of FULL DIFFERENTIATION operation
 * 
 */
TEST_F(FiniteDiffTest, FiniteSecondFullDiff) {

  std::vector<double> true_diffs = this->true_diffs_second_order;
  double h = this->accuracy;

  Finite_Differentiation differ = Finite_Differentiation();
  std::vector<double> diff = differ.finite_diff(2,h,fct_values);

  std::transform(diff.begin(), diff.end(), true_diffs.begin(), diff.begin(), 
    std::minus<double>());

  float (*fabs)(float) = &std::abs;
  std::transform(diff.begin(), diff.end(), diff.begin(), fabs);

  ASSERT_THAT(diff, testing::Each(testing::AllOf(testing::Le(h))));
}