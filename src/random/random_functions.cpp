#include "random/random_functions.h"
#include <ctime>
#include <memory>
#include "random/Random.h"

namespace cuhksz {
namespace {
cuhksz::Random& getInitializedGenerator() {
  static bool initialized;
  static std::unique_ptr<cuhksz::Random> randomGenerator;
  if (!initialized) {
    randomGenerator.reset(new cuhksz::Random());
    initialized = true;
  }
  return *randomGenerator;
}
}  // namespace

int randomInt() {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt();
}

int randomInt(int min) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt(min);
}
int randomInt(int min, int max) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextInt(min, max);
}
double randomDouble(double min, double max) {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextDouble(min, max);
}
double randomDouble(double max) { return randomDouble(0, max); }
double randomDouble() { return randomDouble(0, 1); }
bool randomBool() {
  auto& randomGenerator = getInitializedGenerator();
  return randomGenerator.nextBool();
}

}  // namespace cuhksz
