#include <cstdio>

struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct FileLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[file] %ld -> %ld: %f\n", from, to, amount);
  }
};

// Constructor Injection
struct CBank {
  CBank(Logger& logger) : logger{logger} {}
  void make_transfer(long from, long to, double amount) {
    // -- snip --
    logger.log_transfer(from, to, amount);
  }

 private:
  Logger& logger;
};

// Property Injection
struct PBank {
  void set_logger(Logger* new_logger) { logger = new_logger; }
  void make_transfer(long from, long to, double amount) {
    logger->log_transfer(from, to, amount);
  }

 private:
  Logger* logger{};
};

int main() {
  ConsoleLogger console_logger;
  FileLogger file_logger;

  // constructor injection
  CBank cbank{console_logger};
  cbank.make_transfer(1000, 2000, 49.95);
  cbank.make_transfer(2000, 4000, 20.00);

  // property injection
  PBank pbank{};
  pbank.set_logger(&console_logger);
  pbank.make_transfer(1000, 2000, 49.95);
  pbank.set_logger(&file_logger);
  pbank.make_transfer(2000, 4000, 20.00);
}