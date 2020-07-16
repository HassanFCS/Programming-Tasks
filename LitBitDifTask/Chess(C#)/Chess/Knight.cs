using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    class Knight : Piece
    {
        MyColor KnightColor;
        public Knight(MyColor C, string n) : base(C, n)
        {
            col = C;
            KnightColor = C;
            PictureName = n;
            IsKing = false;
        }

        public override bool IsLegal(int sr, int sc, int er, int ec, Piece[,] Ps)
        {
            return (((Math.Abs(sr - er) == 2 && Math.Abs(sc - ec) == 1) || (Math.Abs(sr - er) == 1 && Math.Abs(sc - ec) == 2))
                && (Ps[er, ec] == null || Ps[er, ec].col != KnightColor));
        }
    }
}
