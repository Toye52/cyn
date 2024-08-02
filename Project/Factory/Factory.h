#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>

// 抽象产品类
class Product
{
public:
    virtual void process() = 0;
    void setStrategy_(std::unique_ptr<class Strategy> strategy);
    virtual ~Product() = default;

protected:
    std::unique_ptr<class Strategy> strategy_;
};

class ProductA : public Product
{
public:
    void process() override;
};

class ProductB : public Product
{
public:
    void process() override;
};

class ProductC : public Product
{
public:
    void process() override;
};

// 抽象策略接口
class Strategy
{
public:
    virtual void operate() = 0;
    virtual ~Strategy() = default;
};

class Heat : public Strategy
{
public:
    void operate() override;
};

class Cold : public Strategy
{
public:
    void operate() override;
};

class Mix : public Strategy
{
public:
    void operate() override;
};

// 策略工厂类
class StrategyFactory
{
public:
    std::unique_ptr<Strategy> buildStrategy(const std::string plan);
    ~StrategyFactory() = default;
};

// 产品工厂类
class ProductFactory
{
public:
    std::unique_ptr<Product> create_(const std::string &type);
};

// 工厂管理者类
class FactoryManager
{
public:
    static FactoryManager &getInstance(); // 实现单例
    std::unique_ptr<Product> createProduct(const std::string &plan);
    void assignStrategy(Product *product, const std::string &type);
    FactoryManager() = default;

private:
    ProductFactory productfactory_;
    StrategyFactory strategyfactory_;
};

#endif // FACTORY_H