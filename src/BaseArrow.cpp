#include "BaseArrow.h"

void BaseArrow::hovering(bool mouseHovering)
{
    bool textureWasModificated{ m_currentTexture == Texture::hover };

    // more frequently than not, the mouse is not hovering over the arrow
    if (!mouseHovering && textureWasModificated)
    {
        setStandardTexture();
        m_currentTexture = Texture::standard;
    }
    else if (mouseHovering && !textureWasModificated)
    {
        setHoverTexture();
        m_currentTexture = Texture::hover;
    }
}

bool BaseArrow::isHovering(const sf::Vector2f& mousePos)
{
    return m_arrow.getBounds().contains(mousePos);
}

void BaseArrow::draw(sf::RenderWindow& window) const
{
    window.draw(m_arrow, &m_texture);
}