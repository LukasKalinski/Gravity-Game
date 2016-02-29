///////////////////////////////////////////////////////////
//  Shape.h
//  Implementation of the Class Shape
//  Created on:      28-mar-2008 10:33:03
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_221DFDDD_B7BB_4f62_B5A5_70666D68DA70__INCLUDED_)
#define EA_221DFDDD_B7BB_4f62_B5A5_70666D68DA70__INCLUDED_

/**
 * A geometric shape and its orientation.
 */
class Shape
{

public:

	/**
	 * Constructs a shape.
	 * 
	 * @param orientation
	 */
	Shape(float orientation);

	virtual ~Shape();
	Shape(const Shape& shape);

	/**
	 * Clones the shape, returning a pointer to the created clone.
	 */
	virtual Shape* clone() const = 0;

	/**
	 * Sets the shape's orientation according to the unit circle.
	 * 
	 * @param orientation
	 */
	void setOrientation(float orientation);

	/**
	 * Returns the angle of orientation, according to the unit circle.
	 */
	float getOrientation() const;

	/**
	 * Returns the radius of a shape. Shapes that aren't circles
	 * needs a radius anyway becuase they are treated like circles
	 * sometimes.
	 */
	virtual float getRadius() const = 0;

protected:

	/**
	 * The orientation of the shape according to the unit circle (i.e., in what
	 * direction it is "pointing").
	 */
	float m_orientation;
};
#endif // !defined(EA_221DFDDD_B7BB_4f62_B5A5_70666D68DA70__INCLUDED_)
