#include <iostream>
#include <string>


// Клас Місце
class Place {
protected:
    std::string name;
public:
    Place(const std::string& name) : name(name) {}
    virtual ~Place() {}
    virtual void print() const {
        std::cout << "Place: " << name << std::endl;
    }
};

// Клас Область
class Region : public Place {
protected:
    std::string region_center;
public:
    Region(const std::string& name, const std::string& region_center)
        : Place(name), region_center(region_center) {}
    ~Region() override {}
    void print() const override {
        std::cout << "Region: " << name << ", center: " << region_center << std::endl;
    }
};

// Клас Місто
class City : public Region {
protected:
    int population;
public:
    City(const std::string& name, const std::string& region_center, int population)
        : Region(name, region_center), population(population) {}
    ~City() override {}
    void print() const override {
        std::cout << "City: " << name << ", center: " << region_center
            << ", population: " << population << std::endl;
    }
};

// Клас Мегаполіс
class Metropolis : public City {
protected:
    std::string metropolis_center;
public:
    Metropolis(const std::string& name, const std::string& region_center, int population,
        const std::string& metropolis_center) : City(name, region_center, population),
        metropolis_center(metropolis_center) {}
    ~Metropolis() override {}
    void print() const override {
        std::cout << "Metropolis: " << name << ", center: " << metropolis_center
            << ", region center: " << region_center << ", population: " << population << std::endl;
    }
};

int main() {
    // Створюємо об'єкти різних класів
    Place place("Some Place");
    Region region("Some Region", "Region Center");
    City city("Some City", "City Center", 1000000);
    Metropolis metropolis("Some Metropolis", "Metropolis Center", 10000000, "Region Center");

    // Викликаємо метод print() для кожного об'єкту
    place.print();
    region.print();
    city.print();
    metropolis.print();

    return 0;
}
