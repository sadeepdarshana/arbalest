
#ifndef RT3_DOCKABLE_H
#define RT3_DOCKABLE_H


#include <QtWidgets/QScrollArea>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <unordered_map>

/*
 *  A class customized wrapper for QDockWidget to make it scrollable and support default width sizes
 */

class Dockable: public QDockWidget {
public:

    // A wrapper so I can override sizeHint
    class DefaultWidthScrollArea: public QScrollArea{
    public:
        explicit DefaultWidthScrollArea(QWidget *parent,int defaultWidth) : QScrollArea(parent), defaultWidth(defaultWidth) {}
        QSize sizeHint() const override;
    private:
        int defaultWidth;
    };

    Dockable(const QString &dockableTitle, QWidget *mainWindow, bool scrollable, int width = -1);
    ~Dockable() override;
	
    void clear();
    void setContent(QWidget *content);
    void hideHeader();

private:
    QLabel *title;
    bool scrollable;
    int width;
    //QWidget * fillerWidget;

    class : public QWidget
    {
    public:
        QSize sizeHint() const  override{
            QSize hint = QWidget::sizeHint();
            if(width != -1) hint.setWidth(width);
            return hint;
        }
        int width=-1;
    } fillerWidget;

    std::unordered_map< QWidget*, QScrollArea *> widgetToScrollAreaMap;
};


#endif //RT3_DOCKABLE_H
