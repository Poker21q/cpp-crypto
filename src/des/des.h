//
// Created by Scott Sirius on 06.02.2025.
//

#ifndef CPP_CRYPTO_SRC_DES_DES_H_
#define CPP_CRYPTO_SRC_DES_DES_H_

#include <cstddef>
#include <optional>
#include <vector>

namespace s21 {
class DataEncryptionStandardECB {
 public:
  std::optional<std::vector<std::byte>> Encode(
      const std::vector<std::byte> &data, const std::vector<std::byte> &key);

  std::optional<std::vector<std::byte>> Decode(
      const std::vector<std::byte> &data, const std::vector<std::byte> &key);

 private:
  void InitialPermutation(std::vector<std::byte> &data);
  void Encryption(std::vector<std::byte> &data,
                  const std::vector<std::byte> &key);
  void FinalPermutation(std::vector<std::byte> &data);

  inline size_t BytesToBits(size_t byte);
  inline size_t BitsToBytes(size_t bit);
};
}  // namespace s21

#endif  // CPP_CRYPTO_SRC_DES_DES_H_
