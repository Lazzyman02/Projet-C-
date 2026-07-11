class Entity {
public:
    Entity();
    virtual ~Entity();
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
protected:
    float x, y;
};