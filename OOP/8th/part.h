#ifndef PART_H
#define PART_H

#include <string>
#include <typeinfo>

class Part {
 public:
  virtual ~Part();
  explicit Part(std::string factory_name);
  virtual std::string GetInfo() const = 0;
  std::string factory_name() const;
 private:
  const std::string factory_name_;
};

#endif  // PART_H
