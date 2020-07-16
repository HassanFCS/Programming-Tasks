using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;


namespace Chess
{
    class Cell : Button
    {
        public int ri;
        public int ci;
        public MyColor Col;
        public Piece aP;

        public Cell(int r, int c, MyColor C, Piece P, int W, int H, int D)
        {
            ri = r;
            ci = c;
            Col = C;
            aP = P;
            this.Width = W / D - 9;
            this.Height = H / D - 9;
            if (C==MyColor.Black)
            {
                this.BackColor = Color.Gray;
            }
            if (aP!=null)
            {
                aP.Draw(this);
            }

        }
    }
}
