using UnityEngine;
using UnityEngine.UI;

public class UIController : MonoBehaviour
{
    public Text text;
    public static bool gameOver;
    public GameObject button;

    void Start()
    {
        text.enabled = false;
        button.SetActive(false);
    }

    void Update()
    {
        if(gameOver)
        {
            text.enabled = true;
            button.SetActive(true);
        }
    }
}
