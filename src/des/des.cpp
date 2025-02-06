//
// Created by Scott Sirius on 06.02.2025.
//

#include "des.h"

namespace s21 {
std::optional<std::vector<std::byte>> DataEncryptionStandardECB::Encode(
    const std::vector<std::byte> &data, const std::vector<std::byte> &key) {
  if (key.size() != BitsToBytes(64UL)) {
    return std::optional<std::vector<std::byte>>();
  }

  std::vector<std::byte> res{data};

  InitialPermutation(res);
  Encryption(res, key);
  FinalPermutation(res);

  return res;
}
// namespace s21

void DataEncryptionStandardECB::InitialPermutation(
    std::vector<std::byte> &data) {
  const std::array<std::array<int, 8>, 8> kIpMatrix = {
      {{58, 50, 42, 34, 26, 18, 10, 2},
       {60, 52, 44, 36, 28, 20, 12, 4},
       {62, 54, 46, 38, 30, 22, 14, 6},
       {64, 56, 48, 40, 32, 24, 16, 8},
       {57, 49, 41, 33, 25, 17, 9, 1},
       {59, 51, 43, 35, 27, 19, 11, 3},
       {61, 53, 45, 37, 29, 21, 13, 5},
       {63, 55, 47, 39, 31, 23, 15, 7}}};

  const size_t kBlockBytes = BitsToBytes(64UL);
}

void DataEncryptionStandardECB::Encryption(std::vector<std::byte> &data,
                                           const std::vector<std::byte> &key) {
  auto subKeys = GenerateSubKeys(key);

  const size_t kFeistelRoundsCount{16};

  for (size_t i = 0; i < kFeistelRoundsCount; ++i) {
    EncryptionRoundProcess(data, key);
  }
}

void DataEncryptionStandardECB::FinalPermutation(std::vector<std::byte> &data) {
  // Реализация конечной перестановки (FP)
}

std::vector<std::byte> DataEncryptionStandardECB::GenerateSubKeys(
    const std::vector<std::byte> &key) {
  // Генерация 16 подключей на основе основного ключа
  std::vector<std::byte> subKeys;
  return subKeys;
}

inline size_t DataEncryptionStandardECB::BytesToBits(size_t byte) {
  return byte * 8;
}

inline size_t DataEncryptionStandardECB::BitsToBytes(size_t bit) {
  return bit / 8;
}
}  // namespace s21