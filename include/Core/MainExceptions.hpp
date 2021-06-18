/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <exception>
#include <string>

class MainException : public std::exception {
public:
    MainException();
    explicit MainException(std::string str);
    ~MainException() override = default;

    char const *what() const noexcept override;

private:
    std::string exceptionMessage;
};

#endif /* !EXCEPTIONS_HPP_ */