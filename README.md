This is the full stack version of my cardgame program (blackjack for now)!

Feel free to have a browse. For now I am keeping it simple but I plan to add actual playing cards with the QGraphicsView Framework and a QGraphicsScene.

Overview of QGraphicsView

QGraphicsView is a widget in the Qt framework that displays the contents of a QGraphicsScene. It is part of the Graphics View Framework, which allows for the visualization of 2D graphics in a scrollable viewport.
Key Components
QGraphicsView

    Displays the scene.
    Can be customized to show different parts of the scene.
    Supports transformations like scaling and rotating.

QGraphicsScene

    Acts as a container for graphical items (QGraphicsItems).
    Manages a large number of 2D graphical items, such as shapes and text.
    Defines the boundaries of the scene with a scene rectangle.

QGraphicsItem

    Represents individual items within the scene.
    Can be shapes, text, or custom items.

Basic Usage

    Creating a Scene:
        Instantiate a QGraphicsScene object.
        Define its boundaries using setSceneRect() if needed.

    Creating a View:
        Instantiate a QGraphicsView object and set the scene using setScene(scene).

    Adding Items:
        Use methods like addEllipse(), addRect(), or addText() on the QGraphicsScene to add items.

    Displaying the View:
        Call show() on the QGraphicsView to display it.

Example code from copilot:

    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 400, 400); // Set scene boundaries

    QGraphicsView *view = new QGraphicsView(scene);
    view->show(); // Display the view

    // Adding items to the scene
    scene->addEllipse(10, 10, 100, 100, QPen(Qt::black), QBrush(Qt::green));
    scene->addText("Hello, QGraphicsView!");
    
