#include "image.h"

#include <fstream>
#include <iostream>
#include <string>

const size_t EIGHT = 8;
const size_t HOW_MUCH = 0xFF;

class BinaryReader {
private:
    std::ifstream eps_;

public:
    explicit BinaryReader(const std::string& crt) {
        eps_ = std::ifstream(crt, std::ios_base::binary);
    }
    template <typename T>
    BinaryReader& operator>>(T& value) {
        using U = typename std::make_unsigned<T>::type;
        U bits = 0;
        unsigned char buffer[sizeof(T)];
        eps_.read(reinterpret_cast<char*>(buffer), sizeof(T));
        for (size_t index = 0; index < sizeof(T); ++index) {
            bits = (bits << U(EIGHT)) | buffer[sizeof(T) - index - 1];
        }
        value = static_cast<T>(bits);
        return *this;
    };

    void Read(char* buffer, std::streamsize count) {
        eps_.read(buffer, count);
    }
};

class BinaryWriter {
public:
    explicit BinaryWriter(const std::string& out_path) {
        out_ = std::ofstream(out_path, std::ios_base::binary);
    }

    template <typename T>
    BinaryWriter& operator<<(T value) {
        using Res = typename std::make_unsigned<T>::type;
        Res bits = static_cast<Res>(value);
        unsigned char buffer[sizeof(T)];
        for (unsigned char& byte : buffer) {
            byte = bits & Res{HOW_MUCH};
            if (sizeof(bits) > 1) {
                bits >>= static_cast<int>(EIGHT);
            } else {
                bits = 0;
            }
        }

        out_.write(reinterpret_cast<char*>(buffer), sizeof(T));
        return *this;
    }

    void Write(const char* data, std::streamsize count) {
        out_.write(data, count);
    }

private:
    std::ofstream out_;
};
