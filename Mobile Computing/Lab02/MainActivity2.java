package com.example.lab02;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent il=getIntent();
        String Str=il.getStringExtra("msg1");
        TextView TV=findViewById(R.id.R2Window);
        TV.setText(Str);
    }

    public void OnClick_Send(View view){
        EditText TB=findViewById(R.id.S2Window);
        String Str=TB.getText().toString();
        Intent i=new Intent(this, MainActivity.class);
        i.putExtra("msg1", Str);
        startActivity(i);
    }
}
