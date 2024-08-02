#include "Factory.h"

void Product::setStrategy_(std::unique_ptr<class Strategy> strategy)
{
    strategy_ = std::move(strategy);
}

void ProductA::process()
{
    strategy_->operate();
}

void ProductB::process()
{
    strategy_->operate();
}

void ProductC::process()
{
    strategy_->operate();
}

void Heat::operate()
{
    std::cout << "Heating strategy" << std::endl;
}

void Cold::operate()
{
    std::cout << "Cooling strategy" << std::endl;
}

void Mix::operate()
{
    std::cout << "Mixing strategy" << std::endl;
}

std::unique_ptr<Strategy> StrategyFactory::buildStrategy(const std::string plan)
{
    if (plan == "Heating")
    {
        return std::make_unique<Heat>();
    }
    else if (plan == "Cooling")
    {
        return std::make_unique<Cold>();
    }
    else if (plan == "Mixing")
    {
        return std::make_unique<Mix>();
    }
    else
    {
        return nullptr;
    }
}

std::unique_ptr<Product> ProductFactory::create_(const std::string &product_)
{
    if (product_ == "ProductA")
    {
        return std::make_unique<ProductA>();
    }
    else if (product_ == "ProductB")
    {
        return std::make_unique<ProductB>();
    }
    else if (product_ == "ProductC")
    {
        return std::make_unique<ProductC>();
    }
    else
    {
        return nullptr;
    }
}

FactoryManager &FactoryManager::getInstance()
{
    static FactoryManager instance; // 创建唯一的实例
    return instance;
}

std::unique_ptr<Product> FactoryManager::createProduct(const std::string &plan)
{
    return productfactory_.create_(plan);
}

void FactoryManager::assignStrategy(Product *product, const std::string &type)
{
    std::unique_ptr<Strategy> strategy = strategyfactory_.buildStrategy(type);
    product->setStrategy_(std::move(strategy));
}
