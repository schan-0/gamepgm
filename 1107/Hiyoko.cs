using UnityEngine;

public class Hiyoko : MonoBehaviour
{
    public float power = 6.5f;
    private GameObject target;
       void Start()
    {
        target = GameObject.FindGameObjectWithTag("DeathZone");
    }

    void FixedUpdate()
    {
        Vector3 direction = target.transform.position - transform.position;
        GetComponent<Rigidbody>().AddForce(direction.normalized * power);
        transform.LookAt(direction);
    }
   
}
