#pragma once

#include <exception>
#include <string>

class ImageProcessorException : public std::exception {
public:
    explicit ImageProcessorException(const std::string& message) : ans_(message) {
    }

    const char* what() const noexcept override {
        return ans_.c_str();
    }

private:
    std::string ans_;
};

class ControllerException : public ImageProcessorException {
public:
    explicit ControllerException(const std::string& message)
        : ImageProcessorException("controller problem: " + message) {
    }
};

class FilterException : public ImageProcessorException {
public:
    explicit FilterException(const std::string& message) : ImageProcessorException("Filter problem: " + message) {
    }
};

class ParserException : public ImageProcessorException {
public:
    explicit ParserException(const std::string& message) : ImageProcessorException("Parser problem: " + message) {
    }
};

class BMPException : public ImageProcessorException {
public:
    explicit BMPException(const std::string& message) : ImageProcessorException("Parser problem: " + message) {
    }
};
