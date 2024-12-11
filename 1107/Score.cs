using UnityEngine;
using UnityEngine.UI;

public class Score : MonoBehaviour
{
    public static int score;
    private Text text;

    void Start() 
    {
        text = GetComponent<Text>();
    }

    void Update()
    {
        text.text = "Score :" + score.ToString();
    }
}
