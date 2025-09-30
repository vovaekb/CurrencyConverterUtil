#pragma once

#include <string>

class CurConverter
{
private:
    std::string m_apiKey;
    std::string m_url;
    std::string m_domainUrl;
public:
    CurConverter(std::string apiKey);
    ~CurConverter();

    float getRate(std::string curFrom, std::string curTo);
};
