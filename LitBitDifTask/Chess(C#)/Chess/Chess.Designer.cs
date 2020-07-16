namespace Chess
{
    partial class Chess
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Start = new System.Windows.Forms.Button();
            this.ChessPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.TurnMessage = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Start
            // 
            this.Start.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Start.Location = new System.Drawing.Point(399, 12);
            this.Start.Name = "Start";
            this.Start.Size = new System.Drawing.Size(123, 64);
            this.Start.TabIndex = 0;
            this.Start.Text = "Lets Play Chess";
            this.Start.UseVisualStyleBackColor = true;
            this.Start.Click += new System.EventHandler(this.Start_Click);
            // 
            // ChessPanel
            // 
            this.ChessPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ChessPanel.Location = new System.Drawing.Point(21, 95);
            this.ChessPanel.Name = "ChessPanel";
            this.ChessPanel.Size = new System.Drawing.Size(904, 673);
            this.ChessPanel.TabIndex = 1;
            // 
            // TurnMessage
            // 
            this.TurnMessage.BackColor = System.Drawing.SystemColors.Control;
            this.TurnMessage.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.TurnMessage.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TurnMessage.Location = new System.Drawing.Point(680, 30);
            this.TurnMessage.Name = "TurnMessage";
            this.TurnMessage.Size = new System.Drawing.Size(147, 35);
            this.TurnMessage.TabIndex = 2;
            this.TurnMessage.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.TurnMessage.TextChanged += new System.EventHandler(this.TurnMessage_TextChanged);
            // 
            // Chess
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(946, 781);
            this.Controls.Add(this.TurnMessage);
            this.Controls.Add(this.ChessPanel);
            this.Controls.Add(this.Start);
            this.Name = "Chess";
            this.Text = "Chess";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Start;
        private System.Windows.Forms.FlowLayoutPanel ChessPanel;
        private System.Windows.Forms.TextBox TurnMessage;
    }
}

