#pragma once

#include <glm/glm.hpp>

// www.lighthouse3d.com/tutorials/view-frustum-culling/geometric-approach-testing-boxes-ii/
class Frustum
{
public:
    Frustum() = default;

    void setInternals(float angle, float ratio, float nearD, float farD);
    void setCam(const glm::vec3 &p, const glm::vec3 &l, const glm::vec3 &u);
    bool boxInFrustum(const glm::vec3 &a, const glm::vec3 &w);

    float getFov() const { return m_angle; };
    float getRatio() const { return m_ratio; };
    float getNear() const { return m_nearD; };
    float getFar() const { return m_farD; };

private:
    class Plane
    {
    public:
        void setPoints(const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3);
        void set(const glm::vec3 &norm, const glm::vec3 &p);
        float distance(const glm::vec3 &p);

        const glm::vec3 &getNormal() { return m_normal; };

    private:
        glm::vec3 m_normal, m_point;
        float m_d;
    };

    glm::vec3 getMaxVert(const glm::vec3 &corner, const glm::vec3 &size, const glm::vec3 &norm);
    glm::vec3 getMinVert(const glm::vec3 &corner, const glm::vec3 &size, const glm::vec3 &norm);

    Plane m_p[6];
    glm::vec3 m_ntl, m_ntr, m_nbl, m_nbr, 
              m_ftl, m_ftr, m_fbl, m_fbr;
    float m_nearD, m_farD, m_ratio, m_angle, m_tanG;
    float m_nw, m_nh, m_fw, m_fh;
};