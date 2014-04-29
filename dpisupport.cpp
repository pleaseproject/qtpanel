#include "dpisupport.h"

#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QApplication>                                                            
#include <QDesktopWidget>                                                          
#else                                                                              
#include <QtGui/QApplication>                                                      
#include <QtGui/QDesktopWidget>                                                    
#endif

int adjustHardcodedPixelSize(int size)
{
    static int dpi = qApp->desktop()->logicalDpiX();
    return size*dpi/96;
}
