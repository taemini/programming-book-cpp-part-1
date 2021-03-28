#include <cstdio>
#include <stdexcept>

struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) const = 0;
  virtual void log_remainings(long from, double from_remainings, long to,
                              double to_remainings) const = 0;
};

struct AccountDatabase {
  virtual ~AccountDatabase() = default;
  virtual double get_amounts(long account) const = 0;
  virtual bool set_amounts(long account, double amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
  double get_amounts(long account) const override { return amounts[account]; }
  bool set_amounts(long account, double amount) override {
    if (account >= 10000) {
      return false;
    }
    amounts[account] = amount;
    return true;
  }

 private:
  double amounts[10000]{};
};

struct ConsoleLogger : Logger {
  ConsoleLogger(const char* label) : label{label} {}
  void log_transfer(long from, long to, double amount) const override {
    printf("[%s] %ld -> %ld: %f\n", label, from, to, amount);
  }
  void log_remainings(long from, double from_remainings, long to,
                      double to_remainings) const override {
    printf("[%s] %ld (%f), %ld (%f)\n", label, from, from_remainings, to,
           to_remainings);
  }

 private:
  const char* label{};
};

struct FileLogger : Logger {
  FileLogger(const char* label) : label{label} {}
  void log_transfer(long from, long to, double amount) const override {
    printf("[%s] %ld -> %ld: %f\n", label, from, to, amount);
  }
  void log_remainings(long from, double from_remainings, long to,
                      double to_remainings) const override {
    printf("[%s] %ld (%f), %ld (%f)\n", label, from, from_remainings, to,
           to_remainings);
  }

 private:
  const char* label{};
};

// Constructor Injection
struct CBank {
  CBank(Logger& logger, AccountDatabase& database)
      : logger{logger}, database{database} {}
  void make_transfer(long from, long to, double amount) {
    database.set_amounts(from, database.get_amounts(from) - amount);
    database.set_amounts(to, database.get_amounts(to) + amount);
    logger.log_transfer(from, to, amount);
    logger.log_remainings(from, database.get_amounts(from), to,
                          database.get_amounts(to));
  }

 private:
  Logger& logger;
  AccountDatabase& database;
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
  ConsoleLogger console_logger{"cons"};
  FileLogger file_logger{"file"};
  InMemoryAccountDatabase in_memory_database;

  // constructor injection
  CBank cbank{console_logger, in_memory_database};
  cbank.make_transfer(1000, 2000, 49.95);
  cbank.make_transfer(2000, 4000, 20.00);

  // property injection
  PBank pbank{};
  pbank.set_logger(&console_logger);
  pbank.make_transfer(1000, 2000, 49.95);
  pbank.set_logger(&file_logger);
  pbank.make_transfer(2000, 4000, 20.00);
}